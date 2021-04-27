/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:05:40 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/27 13:50:44 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H

# include "libft.h"
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/syscall.h>
# include <stdio.h>
# include <elf.h>

typedef uint16_t	t_arch;
typedef uint16_t	t_endian;

# define LENDIAN ELFDATA2LSB
# define BENDIAN ELFDATA2MSB

# define E_ARGS 0x0
# define E_NOFILE 0x1
# define E_NOMEM 0x2
# define E_INVALID 0x3
# define E_NOEXEC 0x4

typedef enum		e_type
{
	ELF_ADDR,
	ELF_OFF,
	ELF_HDR,
	ELF_PHDR,
	ELF_SHDR,
}					t_type;

typedef struct		s_file
{
	void		*ptr;
	void		*end;
	off_t		size;
	t_arch		arch;
	t_endian	endian;
	int			fd;
}					t_file;

int					check_file(char *filename, t_file *file, int *error);
void				woody_error(int error, t_file *file);
uint16_t			get_uint16(uint16_t byte, t_endian endian);
uint32_t			get_uint32(uint32_t byte, t_endian endian);
uint64_t			get_uint64(uint64_t byte, t_endian endian);
Elf64_Shdr			*get_code_shdr(t_file *file);

#endif