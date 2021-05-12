/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:39:27 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/12 14:57:59 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static char		*get_section_strtab(t_file *file)
{
	Elf64_Ehdr	*header;
	Elf64_Shdr	*section;
	uint16_t	index;

	header = file->ptr;
	index = get_uint16(header->e_shstrndx, file->endian);
	section = file->ptr + get_uint64(header->e_shoff, file->endian);
	if (index == SHN_UNDEF)
		return (NULL);
	if (index == SHN_LORESERVE)
		index = get_uint32(section->sh_link, file->endian);
	return (file->ptr + section[index].sh_offset);
}

void			get_text_sect(t_file *file)
{
	Elf64_Shdr	*section;
	uint16_t	nb_sects;
	char		*strtab;
	uint16_t	i;

	i = -1;
	section = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_shoff;
	nb_sects = ((Elf64_Ehdr *)file->ptr)->e_shnum;
	if (!(strtab = get_section_strtab(file)))
		return ;
	while (++i < nb_sects && (void *)(section + i) < file->end)
		if (!ft_strcmp(".text", strtab + section[i].sh_name))
			file->text = section + i;
	return ;
}

void			format_payload(t_file *file, t_payload *payload,
					Elf64_Shdr *sect)
{
	uint32_t	last_entry;
	int32_t		rel_entry;
	Elf64_Ehdr	*hdr;

	hdr = file->ptr;
	last_entry = hdr->e_entry;
	rel_entry = last_entry - (sect->sh_addr + payload->i_jmp + sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_jmp, &rel_entry, sizeof(int32_t));
}

void			update_header(t_file *file, Elf64_Shdr *sect)
{
	Elf64_Ehdr	*hdr;

	hdr = file->ptr;
	hdr->e_shnum++;
	hdr->e_entry = sect->sh_addr;
}

void			update_section(Elf64_Shdr *sect, t_file *file,
					t_payload *payload, off_t addr_offset)
{
	sect->sh_offset = file->size + sizeof(Elf64_Shdr);
	sect->sh_addr = sect->sh_offset + addr_offset;
	sect->sh_size = payload->size;
}

void			add_section(t_file *file, t_payload *payload)
{
	Elf64_Shdr	*sect;
	off_t		addr_offset;
	void		*map;
	char		*code;

	if (!(map = malloc(sizeof(Elf64_Shdr) + payload->size + 1)))
		return ;
	get_text_sect(file);
	sect = map;
	code = (char *)(sect + 1);
	ft_memcpy(sect, file->text, sizeof(Elf64_Shdr));
	extend_last_load_segment(file, payload, &addr_offset);
	update_section(sect, file, payload, addr_offset);
	format_payload(file, payload, sect);
	update_header(file, sect);
	ft_memcpy(code, payload->code, payload->size);
	code[payload->size] = 0;
	save_file(file, map, payload->size + sizeof(Elf64_Shdr) + 1);
}