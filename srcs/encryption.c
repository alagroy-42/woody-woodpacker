/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 13:49:16 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/29 14:02:42 by alagroy-         ###   ########.fr       */
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
	text = file->ptr + ((Elf64_Shdr *)file->text)->sh_offset;
	text_size = ((Elf64_Shdr *)file->text)->sh_size;
	data = file->ptr + ((Elf64_Shdr *)file->data)->sh_offset;
	data_size = ((Elf64_Shdr *)file->data)->sh_size;
	if (text > file->end || data > file->end || text + text_size > file->end
			|| data + data_size > file->end)
		return ;
	encrypt(data, data_size, text, text_size);
}