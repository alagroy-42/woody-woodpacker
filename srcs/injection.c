/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:17:38 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/28 15:52:55 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static int	save_file(char *woody, size_t size)
{
	int		fd;

	errno = 0;
	if ((fd = open("woody.tmp", O_WRONLY | O_CREAT | O_TRUNC, 0755)) == -1)
		return (EXIT_FAILURE);
	if (syscall(SYS_rename, "woody.tmp", "woody"))
		return (EXIT_FAILURE);
	write(fd, woody, size);
	close(fd);
	syscall(SYS_unlink, "woody.tmp");
	return (EXIT_SUCCESS);
}

static void	format_payload_32(t_file *file, t_payload *payload,
					Elf32_Addr entry_addr)
{
	uint32_t	last_entry;
	int32_t		rel_entry;
	int32_t		rel_text;
	uint32_t	key_size;
	uint32_t	filesz;
	Elf32_Ehdr	*hdr;

	hdr = file->ptr;
	last_entry = get_uint32(hdr->e_entry, file->endian);
	rel_entry = last_entry - (entry_addr + payload->i_jmp + sizeof(int32_t));
	rel_text = get_uint32(((Elf32_Phdr *)file->text)->p_vaddr, file->endian) - (entry_addr + payload->i_text + sizeof(int32_t));
	filesz = get_uint32(((Elf32_Phdr *)file->text)->p_filesz, file->endian);
	key_size = KEY_SIZE;
	ft_memcpy(payload->code + payload->i_tsize, &filesz, sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_ksize, &key_size, sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_key, &file->key, KEY_SIZE);
	ft_memcpy(payload->code + payload->i_text, &rel_text, sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_jmp, &rel_entry, sizeof(int32_t));
}

static void	format_payload(t_file *file, t_payload *payload,
					Elf64_Addr entry_addr)
{
	uint32_t	last_entry;
	int32_t		rel_entry;
	int32_t		rel_text;
	uint32_t	key_size;
	uint64_t	filesz;
	Elf64_Ehdr	*hdr;

	hdr = file->ptr;
	last_entry = get_uint64(hdr->e_entry, file->endian);
	rel_entry = last_entry - (entry_addr + payload->i_jmp + sizeof(int32_t));
	rel_text = get_uint64(((Elf64_Phdr *)file->text)->p_vaddr, file->endian) - (entry_addr + payload->i_text + sizeof(int32_t));
	filesz = get_uint64(((Elf64_Phdr *)file->text)->p_filesz, file->endian);
	key_size = KEY_SIZE;
	ft_memcpy(payload->code + payload->i_tsize, &filesz, sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_ksize, &key_size, sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_key, &file->key, KEY_SIZE);
	ft_memcpy(payload->code + payload->i_text, &rel_text, sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_jmp, &rel_entry, sizeof(int32_t));
}

static void		create_woody_32(t_file *file, t_woody *woody, size_t *inject_index)
{
	size_t		file_index;

	*inject_index = get_uint32(woody->data_32->p_offset, file->endian)
		+ get_uint32(woody->data_32->p_filesz, file->endian);
	file_index = *inject_index;
	ft_memcpy(woody->ptr, file->ptr, *inject_index);
	if (woody->data_32 && get_uint32(woody->data_32->p_filesz, file->endian)
		!= get_uint32(woody->data_32->p_memsz, file->endian))
	{
		ft_bzero(woody->ptr + *inject_index, get_uint32(woody->data_32->p_memsz,
			file->endian) - get_uint32(woody->data_32->p_filesz, file->endian));
		*inject_index += get_uint32(woody->data_32->p_memsz, file->endian)
			- get_uint32(woody->data_32->p_filesz, file->endian);
		woody->data_32 = woody->ptr + ((void *)woody->data_32 - file->ptr);
		woody->data_32->p_filesz = woody->data_32->p_memsz;
	}
	if (woody->last_32 != woody->data_32)
	{
		*inject_index += get_uint32(woody->last_32->p_offset, file->endian)
			+ get_uint32(woody->last_32->p_filesz, file->endian) - file_index;
		ft_memcpy(woody->ptr + *inject_index, file->ptr + file_index,
			get_uint32(woody->last_32->p_offset, file->endian)
			+ get_uint32(woody->last_32->p_filesz, file->endian) - file_index);
	}
	woody->last_32 = woody->ptr + ((void *)woody->last_32 - file->ptr);
}

// TODO Protect les memcpy
static void		create_woody(t_file *file, t_woody *woody, size_t *inject_index)
{
	size_t		file_index;

	*inject_index = get_uint64(woody->data->p_offset, file->endian)
		+ get_uint64(woody->data->p_filesz, file->endian);
	file_index = *inject_index;
	ft_memcpy(woody->ptr, file->ptr, *inject_index);
	if (woody->data && get_uint64(woody->data->p_filesz, file->endian)
		!= get_uint64(woody->data->p_memsz, file->endian))
	{
		ft_bzero(woody->ptr + *inject_index, get_uint64(woody->data->p_memsz,
			file->endian) - get_uint64(woody->data->p_filesz, file->endian));
		*inject_index += get_uint64(woody->data->p_memsz, file->endian)
			- get_uint64(woody->data->p_filesz, file->endian);
		woody->data = woody->ptr + ((void *)woody->data - file->ptr);
		woody->data->p_filesz = woody->data->p_memsz;
	}
	if (woody->last != woody->data)
	{
		*inject_index += get_uint64(woody->last->p_offset, file->endian)
			+ get_uint64(woody->last->p_filesz, file->endian) - file_index;
		ft_memcpy(woody->ptr + *inject_index, file->ptr + file_index,
			get_uint64(woody->last->p_offset, file->endian)
			+ get_uint64(woody->last->p_filesz, file->endian) - file_index);
	}
	woody->last = woody->ptr + ((void *)woody->last - file->ptr);
}

static void		inject_32(t_file *file, t_payload *payload)
{
	t_woody		woody;
	size_t		inject_index;

	if (!(woody.last_32 = get_last_load_segment_32(file)))
		return (woody_error(file, payload, NULL, ERROR_PH_TRUNC));
	woody.data_32 = get_segment_32(file, is_data_32);
	if (!woody.data_32)
		woody.data_32 = woody.last_32;
	woody.size = get_uint32(woody.last_32->p_offset, file->endian)
		+ get_uint32(woody.last_32->p_filesz, file->endian) + payload->size
		+ (woody.data_32->p_memsz - woody.data_32->p_filesz);
	errno = 0;
	if (!(woody.ptr = malloc(woody.size)))
		return (woody_error(file, payload, &woody, ERROR_ERRNO));
	format_payload_32(file, payload, get_uint32(woody.last_32->p_vaddr, file->endian)
		+ get_uint32(woody.last_32->p_memsz, file->endian));
	create_woody_32(file, &woody, &inject_index);
	ft_memcpy(woody.ptr + inject_index, payload->code, payload->size);
	((Elf32_Ehdr *)woody.ptr)->e_entry = (get_uint32(woody.last_32->p_vaddr,
		file->endian) + get_uint32(woody.last_32->p_memsz, file->endian));
	woody.last_32->p_filesz += get_uint32(payload->size, file->endian);
	woody.last_32->p_memsz += get_uint32(payload->size, file->endian);
	woody.last_32->p_flags |= PF_X;
	if (save_file(woody.ptr, woody.size) == EXIT_FAILURE)
		return (woody_error(file, payload, &woody, ERROR_ERRNO));
	free(woody.ptr);
}

void			inject(t_file *file, t_payload *payload)
{
	t_woody		woody;
	size_t		inject_index;

	if (file->arch == ELFCLASS32)
		return (inject_32(file, payload));
	if (!(woody.last = get_last_load_segment(file)))
		return (woody_error(file, payload, NULL, ERROR_PH_TRUNC));
	woody.data = get_segment(file, is_data);
	if (!woody.data)
		woody.data = woody.last;
	woody.size = get_uint64(woody.last->p_offset, file->endian)
		+ get_uint64(woody.last->p_filesz, file->endian) + payload->size
		+ (woody.data->p_memsz - woody.data->p_filesz);
	errno = 0;
	if (!(woody.ptr = malloc(woody.size)))
		return (woody_error(file, payload, &woody, ERROR_ERRNO));
	format_payload(file, payload, get_uint64(woody.last->p_vaddr, file->endian)
		+ get_uint64(woody.last->p_memsz, file->endian));
	create_woody(file, &woody, &inject_index);
	ft_memcpy(woody.ptr + inject_index, payload->code, payload->size);
	((Elf64_Ehdr *)woody.ptr)->e_entry = (get_uint64(woody.last->p_vaddr,
		file->endian) + get_uint64(woody.last->p_memsz, file->endian));
	woody.last->p_filesz += get_uint64(payload->size, file->endian);
	woody.last->p_memsz += get_uint64(payload->size, file->endian);
	woody.last->p_flags |= PF_X;
	if (save_file(woody.ptr, woody.size) == EXIT_FAILURE)
		return (woody_error(file, payload, &woody, ERROR_ERRNO));
	free(woody.ptr);
}
