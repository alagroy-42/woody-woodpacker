/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 12:10:25 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/29 12:07:33 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static int	parse_header(t_file *file)
{
	unsigned char	*ident;
	Elf64_Ehdr		*header;
	char			magic[4] = {ELFMAG0, ELFMAG1, ELFMAG2, ELFMAG3};

	ident = file->ptr;
	header = file->ptr;
	file->arch = ident[EI_CLASS];
	file->endian = ident[EI_DATA];
	errno = ENOEXEC;
	if (ft_memcmp(magic, ident, 4) || ident[EI_CLASS] == ELFCLASSNONE
		|| ident[EI_DATA] == ELFDATANONE || ident[EI_VERSION] == EV_NONE
		|| !(get_uint16(header->e_machine, file->endian) == EM_386
			|| get_uint16(header->e_machine, file->endian) == EM_X86_64)
		|| get_uint32(header->e_version, file->endian) == EV_NONE
		|| get_uint16(header->e_phnum, file->endian) == 0)
		return (EXIT_FAILURE);
	if (header->e_type != ET_EXEC && header->e_type != ET_DYN)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int			check_file(char *filename, t_file *file)
{
	errno = 0;
	if ((file->fd = open(filename, O_RDONLY)) == -1)
		return (EXIT_FAILURE);
	if ((file->size = lseek(file->fd, 0, SEEK_END)) == (off_t)(-1))
		return (EXIT_FAILURE);
	if ((file->ptr = mmap(NULL, file->size, PROT_READ | PROT_WRITE,
			MAP_PRIVATE, file->fd, 0)) == MAP_FAILED)
		return (EXIT_FAILURE);
	file->end = file->ptr + file->size;
	return (parse_header(file));
}
