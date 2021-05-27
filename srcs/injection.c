/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:17:38 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/27 15:22:07 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void			format_payload(t_file *file, t_payload *payload,
					Elf64_Addr entry_addr)
{
	uint32_t	last_entry;
	int32_t		rel_entry;
	int32_t		rel_text;
	Elf64_Ehdr	*hdr;

	hdr = file->ptr;
	last_entry = hdr->e_entry;
	rel_entry = last_entry - (entry_addr + payload->i_jmp + sizeof(int32_t));
	rel_text = ((Elf64_Phdr *)file->text)->p_vaddr - (entry_addr + payload->i_text + sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_tsize, &((Elf64_Phdr *)file->text)->p_filesz,
			sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_key, &file->key, KEY_SIZE);
	ft_memcpy(payload->code + payload->i_text, &rel_text, sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_jmp, &rel_entry, sizeof(int32_t));
}

static void		create_woody(t_file *file, t_woody *woody, size_t *inject_index)
{
	if (woody->data && woody->data->p_filesz != woody->data->p_memsz)
	{
		*inject_index = woody->data->p_offset + woody->data->p_filesz;
		ft_memcpy(woody->ptr, file->ptr, *inject_index);
		ft_bzero(woody->ptr + *inject_index, woody->data->p_memsz
			- woody->data->p_filesz);
		*inject_index += woody->data->p_memsz - woody->data->p_filesz;
		woody->data = woody->ptr + ((void *)woody->data - file->ptr);
		woody->data->p_filesz = woody->data->p_memsz;
		return ;
	}
	*inject_index = woody->data->p_offset + woody->data->p_filesz;
	ft_memcpy(woody->ptr, file->ptr, *inject_index);
}

void			inject(t_file *file, t_payload *payload)
{
	t_woody		woody;
	size_t		inject_index;

	if (!(woody.last = get_last_load_segment(file)))
		return ;
	woody.data = get_segment(file, is_data);
	if (!woody.data)
		woody.data = woody.last;
	woody.size = woody.last->p_offset + woody.last->p_filesz + payload->size
		+ (woody.data->p_memsz - woody.data->p_filesz);
	if (!(woody.ptr = malloc(woody.size)))
		return ;
	format_payload(file, payload, (woody.last->p_vaddr + woody.last->p_memsz));
	create_woody(file, &woody, &inject_index);
	ft_memcpy(woody.ptr + inject_index, payload->code, payload->size);
	((Elf64_Ehdr *)woody.ptr)->e_entry = (woody.last->p_vaddr + woody.last->p_memsz);
	woody.data->p_flags |= PF_X;
	save_file(file, woody.ptr, woody.size);
}

// void			update_header(t_file *file, Elf64_Shdr *sect)
// {
// 	Elf64_Ehdr	*hdr;

// 	hdr = file->ptr;
// 	hdr->e_shnum++;
// 	hdr->e_entry = sect->sh_addr;
// }

// void			update_section(Elf64_Shdr *sect, t_file *file,
// 					t_payload *payload, off_t addr_offset)
// {
// 	char	*strtab;

// 	sect->sh_offset = file->size + sizeof(Elf64_Shdr);
// 	sect->sh_addr = sect->sh_offset + addr_offset;
// 	sect->sh_size = payload->size;
// 	if (!(strtab = get_section_strtab(file)))
// 		return ;
// 	if (strtab[sect->sh_name] == '.')
// 		sect->sh_name++;
// }

// void			add_section(t_file *file, t_payload *payload)
// {
// 	Elf64_Shdr	*sect;
// 	off_t		addr_offset;
// 	void		*map;
// 	char		*code;
	
// 	if (!(map = malloc(sizeof(Elf64_Shdr) + payload->size + 1)))
// 		return ;
// 	get_text_sect(file);
// 	sect = map;
// 	code = (char *)(sect + 1);
// 	ft_memcpy(sect, file->text, sizeof(Elf64_Shdr));
// 	extend_last_load_segment(file, payload, &addr_offset);
// 	give_text_write_right(file);
// 	update_section(sect, file, payload, addr_offset);
// 	format_payload(file, payload, sect->sh_addr);
// 	update_header(file, sect);
// 	ft_memcpy(code, payload->code, payload->size);
// 	code[payload->size] = 0;
// 	save_file(file, map, payload->size + sizeof(Elf64_Shdr) + 1);
// }

// void		inject(t_file *file, t_payload *payload)
// {
// 	Elf64_Shdr	*sect;
// 	off_t		addr_offset;
// 	char		*code;

// 	sect = get_last_section(file);
// 	if (!(sect->sh_flags & SHF_EXECINSTR))
// 		return (add_section(file, payload));
// 	if (!(code = malloc(payload->size + 1)))
// 		return ;
// 	get_text_sect(file);
// 	extend_last_load_segment(file, payload, &addr_offset);
// 	give_text_write_right(file);
// 	format_payload(file, payload, file->size + addr_offset);
// 	sect->sh_size += payload->size;
// 	((Elf64_Ehdr *)file->ptr)->e_entry = file->size + addr_offset;
// 	ft_memcpy(code, payload->code, payload->size);
// 	code[payload->size] = 0;
// 	save_file(file, code, payload->size + 1);
// }