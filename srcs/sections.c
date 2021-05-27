/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sections.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:39:27 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/27 11:45:45 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

char			*get_section_strtab(t_file *file)
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

Elf64_Shdr		*get_section(t_file *file, char *name)
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
		if (!ft_strcmp(name, strtab + section[i].sh_name))
			return (section + i);
	return (NULL);
}

Elf64_Shdr		*get_last_section(t_file *file)
{
	return ((Elf64_Shdr *)(file->ptr + ((Elf64_Ehdr *)file->ptr)->e_shoff)
		+ ((Elf64_Ehdr *)file->ptr)->e_shnum - 1);
}
