/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:07:31 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/28 12:33:43 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

int			is_text(Elf64_Phdr *phdr)
{
	return (phdr->p_type == PT_LOAD && phdr->p_flags & PF_X
			&& phdr->p_flags & PF_R);
}

int			is_data(Elf64_Phdr *phdr)
{
	return (phdr->p_type == PT_LOAD && phdr->p_filesz != phdr->p_memsz);
}

Elf64_Phdr	*get_segment(t_file *file, int (*f)(Elf64_Phdr *))
{
	Elf64_Phdr	*phdrs;
	uint16_t	i;
	uint16_t	size;

	i = -1;
	size = ((Elf64_Ehdr *)file->ptr)->e_phnum;
	phdrs = file->ptr + ((Elf64_Ehdr *)file->ptr)->e_phoff;
	if ((void *)phdrs < file->ptr)
		return (NULL);
	while (++i < size && (void *)(phdrs + i + 1) < file->end)
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
	while (--size && (void *)(phdrs + size) < file->end)
	{
		if (phdrs[size].p_type == PT_LOAD)
			return (phdrs + size);
	}
	return (NULL);
}
