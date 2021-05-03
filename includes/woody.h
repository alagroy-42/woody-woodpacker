/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 14:05:40 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/29 16:19:45 by alagroy-         ###   ########.fr       */
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

# define DECRYPTION_CODE "50 51 52 56 57 41 50 41 51 pushs b9 %u size_text be %u size_data 48 8d 14 25 %p addr_text 48 8d 3c 25 %p addr_data 4d 31 c0 4d 31 c9

0000000000000029 <routine>:
4a 0f b6 04 07          movzbq (%rdi,%r8,1),%rax
4c 01 c8                add    %r9,%rax
48 31 02                xor    %rax,(%rdx)
48 ff c2                inc    %rdx
49 ff c0                inc    %r8
49 39 f0                cmp    %rsi,%r8
75 07                   jne    46 <loopinstr>
49 83 c1 2a             add    $0x2a,%r9
4d 31 c0                xor    %r8,%r8

0000000000000046 <loopinstr>:
e2 e1                   loop   29 <routine>
41 59                   pop    %r9
41 58                   pop    %r8
5f                      pop    %rdi
5e                      pop    %rsi
5a                      pop    %rdx
59                      pop    %rcx
58                      pop    %rax
e9 26 00 00 00          jmpq   7c <loopinstr+0x36>

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
uint32_t			get_uint32(uint32_t byte, t_endian endian);
uint64_t			get_uint64(uint64_t byte, t_endian endian);
void				get_shdrs(t_file *file);
void				encrypt_code(t_file *file);

#endif
