/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/27 15:14:07 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static void	get_key(t_file *file)
{
	int		fd;
	int		i;

	if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
		perror("imposible to generate key : /dev/urandom:");
	read(fd, file->key, KEY_SIZE);
	close(fd);
	ft_putstr("encryption key : 0x");
	i = -1;
	while (++i < KEY_SIZE)
		printf("%hhx", file->key[i]);
	fflush(NULL);
	ft_putchar('\n');
}

void		encrypt_code(t_file *file)
{
	void		*text;
	void		*key;
	uint32_t	text_size;
	uint32_t	key_size;

	if (!(file->text = get_segment(file, is_text)))
		return ;
	((Elf64_Phdr *)file->text)->p_flags |= PF_W;
	text = file->ptr + get_uint64(((Elf64_Phdr *)file->text)->p_offset,
		file->endian);
	text_size = get_uint64(((Elf64_Phdr *)file->text)->p_filesz, file->endian);
	get_key(file);
	key = &file->key;
	key_size = sizeof(time_t);
	if (text > file->end || text + text_size > file->end)
		return ;
	encrypt(key, key_size, text, text_size);
}