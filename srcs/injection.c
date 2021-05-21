/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   injection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:17:38 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/21 10:30:02 by alagroy-         ###   ########.fr       */
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
	rel_text = ((Elf64_Shdr *)file->text)->sh_addr - (entry_addr + payload->i_text + sizeof(int32_t));
	ft_memcpy(payload->code + payload->i_tsize, &((Elf64_Shdr *)file->text)->sh_size,
			sizeof(uint32_t));
	ft_memcpy(payload->code + payload->i_key, &file->key, KEY_SIZE);
	ft_memcpy(payload->code + payload->i_text, &rel_text, sizeof(int32_t));
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
	char	*strtab;

	sect->sh_offset = file->size + sizeof(Elf64_Shdr);
	sect->sh_addr = sect->sh_offset + addr_offset;
	sect->sh_size = payload->size;
	if (!(strtab = get_section_strtab(file)))
		return ;
	if (strtab[sect->sh_name] == '.')
		sect->sh_name++;
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
	give_text_write_right(file);
	update_section(sect, file, payload, addr_offset);
	format_payload(file, payload, sect->sh_addr);
	update_header(file, sect);
	ft_memcpy(code, payload->code, payload->size);
	code[payload->size] = 0;
	save_file(file, map, payload->size + sizeof(Elf64_Shdr) + 1);
}

void		inject(t_file *file, t_payload *payload)
{
	Elf64_Shdr	*sect;
	off_t		addr_offset;
	char		*code;

	sect = get_last_section(file);
	if (!(sect->sh_flags & SHF_EXECINSTR))
		return (add_section(file, payload));
	if (!(code = malloc(payload->size + 1)))
		return ;
	get_text_sect(file);
	extend_last_load_segment(file, payload, &addr_offset);
	give_text_write_right(file);
	format_payload(file, payload, file->size + addr_offset);
	sect->sh_size += payload->size;
	((Elf64_Ehdr *)file->ptr)->e_entry = file->size + addr_offset;
	ft_memcpy(code, payload->code, payload->size);
	code[payload->size] = 0;
	save_file(file, code, payload->size + 1);
}