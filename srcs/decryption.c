/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 15:54:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/05 17:11:22 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void		save_file(t_file *file)
{
	int		fd;

	errno = 0;
	if ((fd = open("woody", O_WRONLY | O_CREAT | O_TRUNC, 0755)) == -1)
		return ;
	write(fd, file->ptr, file->size);
	close(fd);
}

static void	*find_insert(t_file *file, Elf64_Phdr **phdr_ptr)
{
	Elf64_Phdr	*phdr_table;
	Elf64_Phdr	phdr;
	uint16_t	nb_phdr;
	uint16_t	i;

	phdr_table = file->ptr + get_uint64(((Elf64_Ehdr *)file->ptr)->e_phoff,
		file->endian);
	nb_phdr = get_uint16(((Elf64_Ehdr *)file->ptr)->e_phnum, file->endian);
	i = -1;
	while (++i < nb_phdr && phdr_table + i < (Elf64_Phdr *)file->end)
	{
		phdr = phdr_table[i];
		*phdr_ptr = phdr_table + i;
		if (get_uint64(phdr.p_type, file->endian) == PT_LOAD
			&& get_uint32(phdr.p_flags, file->endian) & PF_X
			&& get_uint32(phdr.p_flags, file->endian) & PF_R
			&& get_uint64(phdr.p_offset, file->endian)
			+ get_uint64(phdr.p_filesz, file->endian) + CODE_SIZE
			< get_uint64((phdr_table + i + 1)->p_offset, file->endian))
			return (file->ptr + phdr.p_offset
				+ get_uint64(phdr.p_filesz, file->endian));
	}
	return (NULL);
}

static void	format_decryption_routine(t_file *file, char shellcode[],
				off_t insert)
{
	uint32_t	text;
	uint32_t	data;
	uint32_t	text_size;
	uint32_t	data_size;

	text = (int32_t)get_int32(get_uint64(((Elf64_Shdr *)file->text)->sh_offset, file->endian) - (insert + I_TEXT + sizeof(int32_t)), file->endian);
	text_size = (uint32_t)(get_uint64(((Elf64_Shdr *)file->text)->sh_size, file->endian));
	data = (int32_t)get_int32(get_uint64(((Elf64_Shdr *)file->data)->sh_addr, file->endian) - (insert + I_DATA + sizeof(int32_t)), file->endian);
	data_size = (uint32_t)(get_uint64(((Elf64_Shdr *)file->data)->sh_size, file->endian));
	ft_memcpy(shellcode, DECRYPTION_CODE, CODE_SIZE);
	ft_memcpy(shellcode + I_SIZE_TEXT, &text_size, sizeof(uint32_t));
	ft_memcpy(shellcode + I_SIZE_DATA, &data_size, sizeof(uint32_t));
	ft_memcpy(shellcode + I_TEXT, &text, sizeof(uint32_t));
	ft_memcpy(shellcode + I_DATA, &data, sizeof(uint32_t));
}

void		inject_decryption_routine(t_file *file)
{
	char		buf[CODE_SIZE];
	void		*insert;
	Elf64_Phdr	*phdr;
	int32_t		rel_entry;
	void		*entry;

	if (!file->text || !file->data || !(insert = find_insert(file, &phdr)))
		return ;
	format_decryption_routine(file, buf, (insert - file->ptr));
	entry = (void *)((Elf64_Ehdr *)file->ptr)->e_entry;
	((Elf64_Ehdr *)file->ptr)->e_entry = get_uint64(phdr->p_vaddr, file->endian)
		+ get_uint64(phdr->p_memsz, file->endian);
	rel_entry = get_int32((int32_t)(uint64_t)(entry - (get_uint64(phdr->p_vaddr,
		file->endian) + get_uint64(phdr->p_memsz, file->endian)
		+ get_uint32(CODE_SIZE, file->endian))), file->endian);
	phdr->p_memsz += get_uint32(CODE_SIZE, file->endian);
	phdr->p_filesz += get_uint32(CODE_SIZE, file->endian);
	phdr->p_flags |= PF_W;
	((Elf64_Shdr *)file->text)->sh_flags |= SHF_WRITE;
	ft_memcpy(buf + I_JMP, &rel_entry, sizeof(int32_t));
	ft_memcpy(insert, buf, CODE_SIZE);
	save_file(file);
}