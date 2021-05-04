/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/05/04 14:57:21 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

void		encrypt_code(t_file *file)
{
	void		*text;
	void		*data;
	uint32_t	text_size;
	uint32_t	data_size;

	get_shdrs(file);
	if (!file->text || !file->data)
		return ;
	text = file->ptr + get_uint64(((Elf64_Shdr *)file->text)->sh_offset,
		file->endian);
	text_size = get_uint64(((Elf64_Shdr *)file->text)->sh_size, file->endian);
	data = file->ptr + get_uint64(((Elf64_Shdr *)file->data)->sh_offset,
		file->endian);
	data_size = get_uint64(((Elf64_Shdr *)file->data)->sh_size, file->endian);
	if (text > file->end || data > file->end || text + text_size > file->end
			|| data + data_size > file->end)
		return ;
	encrypt(data, data_size, text, text_size);
}