/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:05:40 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/05 11:31:04 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOODY_H
# define WOODY_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/mman.h>
# include <sys/syscall.h>
# include <stdio.h>
# include <elf.h>

typedef uint16_t	t_arch;
typedef uint16_t	t_endian;

# define LENDIAN ELFDATA2LSB
# define BENDIAN ELFDATA2MSB

# define DECRYPTION_CODE "\x50\x51\x52\x56\x57\x41\x50\x41\x51\xb9\x00\x00\x00\x00\xbe\x00\x00\x00\x00\x48\x8d\x15\x00\x00\x00\x00\x48\x8d\x3d\x00\x00\x00\x00\x4d\x31\xc0\x4d\x31\xc9\x4a\x0f\xb6\x04\x07\x4c\x01\xc8\x48\x31\x02\x48\xff\xc2\x49\xff\xc0\x49\x39\xf0\x75\x07\x49\x83\xc1\x2a\x4d\x31\xc0\xe2\xe1\xeb\x1d\x5e\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\xba\x0e\x00\x00\x00\x0f\x05\x41\x59\x41\x58\x5f\x5e\x5a\x59\x58\xeb\x13\xe8\xde\xff\xff\xff\x2e\x2e\x2e\x2e\x57\x4f\x4f\x44\x59\x2e\x2e\x2e\x2e\x0a\xe9\x00\x00\x00\x00"

# define I_SIZE_TEXT 0xa
# define I_SIZE_DATA 0xf
# define I_TEXT 0x16
# define I_DATA 0x1d
# define I_JMP CODE_SIZE - sizeof(uint32_t)

# define CODE_SIZE sizeof(DECRYPTION_CODE) - 1
typedef struct		s_file
{
	void		*ptr;
	void		*end;
	void		*text;
	void		*data;
	off_t		size;
	t_arch		arch;
	t_endian	endian;
	int			fd;
}					t_file;

extern void			encrypt(void *data, uint32_t data_len, void *text,
						uint32_t text_len);

int					check_file(char *filename, t_file *file);
void				woody_error(t_file *file);
uint16_t			get_uint16(uint16_t byte, t_endian endian);
int32_t				get_int32(int32_t byte, t_endian endian);
uint32_t			get_uint32(uint32_t byte, t_endian endian);
uint64_t			get_uint64(uint64_t byte, t_endian endian);
void				get_shdrs(t_file *file);
void				encrypt_code(t_file *file);
void				inject_decryption_routine(t_file *file);

#endif
