/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:07:31 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/18 14:09:00 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int			is_text(Elf64_Phdr *phdr)
{
	return (phdr->p_type == PT_LOAD && phdr->p_flags & PF_X
			&& phdr->p_flags & PF_R);
}

int			is_note(Elf64_Phdr *phdr)
{
	return (phdr->p_type == PT_NOTE);
}

Elf64_Phdr	*get_segment(t_file *file, int (*f)(Elf64_Phdr *))
{
	Elf64_Phdr	*phdrs;
	uint16_t	i;
	uint16_t	size;

	i = -1;
	size = ((Elf64_Ehdr *)file->ptr)->e_phnum;
	phdrs = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_phoff;
	while (++i < size)
	{
		if (f(phdrs + i))
			return (phdrs + i);
	}
	return (NULL);
}

Elf64_Phdr	*get_last_load_segment(t_file *file)
{
	Elf64_Phdr	*phdrs;
	uint16_t	size;

	size = ((Elf64_Ehdr *)file->ptr)->e_phnum;
	phdrs = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_phoff;
	while (--size)
	{
		if (phdrs[size].p_type == PT_LOAD)
			return (phdrs + size);
	}
	return (NULL);
}

void		extend_last_load_segment(t_file *file, t_payload *payload,
				off_t *addr_off)
{
	Elf64_Phdr		*seg;
	off_t			length_to_add;

	seg = get_last_load_segment(file);
	length_to_add = file->size - (seg->p_offset + seg->p_filesz) + payload->size
		+ sizeof(Elf64_Shdr);
	seg->p_filesz += length_to_add;
	seg->p_memsz += length_to_add;
	if (!(seg->p_flags & PF_X))
		seg->p_flags |= PF_X;
	*addr_off = seg->p_vaddr - seg->p_offset;
}

void		give_text_write_right(t_file *file)
{
	Elf64_Phdr	*phdrs;
	uint16_t	size;
	uint16_t	i;

	i = -1;
	size = ((Elf64_Ehdr *)file->ptr)->e_phnum;
	phdrs = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_phoff;
	while (++i < size)
	{
		if (phdrs[i].p_type == PT_LOAD && phdrs[i].p_flags & PF_X
				&& phdrs[i].p_flags & PF_R)
		{
			phdrs[i].p_flags |= PF_W;
			return ;
		}
	}
	return ;
}
