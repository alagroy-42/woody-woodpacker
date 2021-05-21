/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/21 13:41:18 by alagroy-         ###   ########.fr       */
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

	get_text_sect(file);
	if (!file->text)
		return ;
	text = file->ptr + get_uint64(((Elf64_Shdr *)file->text)->sh_offset,
		file->endian);
	text_size = get_uint64(((Elf64_Shdr *)file->text)->sh_size, file->endian);
	get_key(file);
	key = &file->key;
	key_size = sizeof(time_t);
	if (text > file->end || text + text_size > file->end)
		return ;
	encrypt(key, key_size, text, text_size);
}