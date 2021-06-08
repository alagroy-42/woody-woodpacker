/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:05:40 by alagroy-          #+#    #+#             */
/*   Updated: 2021/06/08 12:48:47 by alagroy-         ###   ########.fr       */
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

# define DECRYPTION_CODE "\x50\x56\x57\x52\x51\x41\x50\x41\x51\xeb\x55\x5e\xb8\x01\x00\x00\x00\xbf\x01\x00\x00\x00\xba\x0e\x00\x00\x00\x0f\x05\xb9\x2b\x00\x00\x00\xbe\x04\x00\x00\x00\x48\x8d\x15\x09\x00\x00\x00\x4d\x31\xc0\x48\x31\xc0\xeb\x3d\x5f\x42\x8a\x04\x07\x00\xe0\x30\x02\x48\xff\xc2\x49\xff\xc0\x49\x39\xf0\x75\x06\x80\xc4\x2a\x4d\x31\xc0\xe2\xe5\x41\x59\x41\x58\x59\x5a\x5f\x5e\x58\xe9\x26\x00\x00\x00\xe8\xa6\xff\xff\xff\x2e\x2e\x2e\x2e\x57\x4f\x4f\x44\x59\x2e\x2e\x2e\x2e\x0a\xe8\xbe\xff\xff\xff"
# define CODE_SIZE sizeof(DECRYPTION_CODE) -1 + KEY_SIZE

# define DECRYPTION_CODE_32 "\x60\xeb\x4c\x59\xb8\x04\x00\x00\x00\xbb\x01\x00\x00\x00\xba\x0e\x00\x00\x00\xcd\x80\xb9\x2b\x00\x00\x00\xbe\x04\x00\x00\x00\xe8\x27\x00\x00\x00\x81\xea\x00\x00\x01\x00\x31\xdb\x31\xc0\xeb\x32\x5f\x8a\x04\x1f\x00\xe0\x30\x02\x42\x43\x39\xf3\x75\x05\x80\xc4\x2a\x31\xdb\xe2\xec\x61\xe9\x26\x00\x00\x00\x8b\x14\x24\xc3\xe8\xaf\xff\xff\xff\x2e\x2e\x2e\x2e\x57\x4f\x4f\x44\x59\x2e\x2e\x2e\x2e\x0a\xe8\xc9\xff\xff\xff"
# define CODE_SIZE_32 sizeof(DECRYPTION_CODE_32) -1 + KEY_SIZE

# define KEY_SIZE 32

# define ERROR_ERRNO 0
# define ERROR_PH_TRUNC 1
# define ERROR_TEXT_TRUNC 2
# define ERROR_ARGS 3

typedef struct		s_file
{
	void		*ptr;
	void		*end;
	void		*text;
	void		*note;
	char		key[KEY_SIZE];
	off_t		size;
	t_arch		arch;
	t_endian	endian;
	int			fd;
}					t_file;

typedef struct		s_payload
{
	char		*code;
	size_t		size;
	uint16_t	i_tsize;
	uint16_t	i_ksize;
	uint16_t	i_text;
	uint16_t	i_key;
	uint16_t	i_jmp;
}					t_payload;

typedef struct 		s_woody
{
	void		*ptr;
	size_t		size;
	Elf64_Phdr	*data;
	Elf64_Phdr	*last;
	Elf32_Phdr	*data_32;
	Elf32_Phdr	*last_32;
}					t_woody;

extern void			encrypt(void *data, uint32_t data_len, void *text,
						uint32_t text_len);
uint16_t			get_uint16(uint16_t byte, t_endian endian);
int32_t				get_int32(int32_t byte, t_endian endian);
uint32_t			get_uint32(uint32_t byte, t_endian endian);
uint64_t			get_uint64(uint64_t byte, t_endian endian);
Elf64_Phdr			*get_segment(t_file *file, int (*f)(Elf64_Phdr *));
Elf64_Phdr			*get_last_load_segment(t_file *file);
Elf32_Phdr			*get_segment_32(t_file *file, int (*f)(Elf32_Phdr *));
Elf32_Phdr			*get_last_load_segment_32(t_file *file);
int					is_text(Elf64_Phdr *phdr);
int					is_data(Elf64_Phdr *phdr);
int					is_text_32(Elf32_Phdr *phdr);
int					is_data_32(Elf32_Phdr *phdr);
void				inject(t_file *file, t_payload *payload);
void				encrypt_code(t_file *file);
int					check_file(char *filename, t_file *file);
void				woody_error(t_file *file, t_payload *payload,
						t_woody *woody, int code);

#endif
