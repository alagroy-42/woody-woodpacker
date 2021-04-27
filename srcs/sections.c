/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:39:27 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/27 15:19:17 by alagroy-         ###   ########.fr       */
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

Elf64_Shdr		*get_code_shdr(t_file *file)
{
	Elf64_Shdr	*section;
	uint16_t	nb_sects;
	char		*strtab;
	uint16_t	i;

	i = -1;
	section = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_shoff;
	nb_sects = ((Elf64_Ehdr *)file->ptr)->e_shnum;
	if (!(strtab = get_section_strtab(file)))
		return (NULL);
	while (++i < nb_sects && (void *)(section + i) < file->end)
		if (!ft_strcmp(".text", strtab + section[i].sh_name))
			return (section + i);
	return (NULL);
}