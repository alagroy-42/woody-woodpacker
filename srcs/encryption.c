/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/20 17:05:31 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

static void	get_key(t_file *file)
{
	file->key = syscall(SYS_time, NULL);
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