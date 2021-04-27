/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endian.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:31:20 by alagroy-          #+#    #+#             */
/*   Updated: 2021/04/27 10:55:45 by alagroy-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody.h"

uint16_t		get_uint16(uint16_t byte, t_endian endian)
{
	if (endian == LENDIAN)
		return (byte);
	return ((byte << 8) | (byte >> 8));
}

uint32_t		get_uint32(uint32_t byte, t_endian endian)
{
	if (endian == LENDIAN)
		return (byte);
	byte = ((byte << 8) & 0xFF00FF00) | ((byte >> 8) & 0xFF00FF);
	return (byte << 16) | (byte >> 16);
}

uint64_t		get_uint64(uint64_t byte, t_endian endian)
{
	if (endian == LENDIAN)
		return (byte);
	byte = ((byte << 8) & 0xFF00FF00FF00FF00ULL)
		| ((byte >> 8) & 0x00FF00FF00FF00FFULL);
	byte = ((byte << 16) & 0xFFFF0000FFFF0000ULL)
		| ((byte >> 16) & 0x0000FFFF0000FFFFULL);
	return (byte << 32) | (byte >> 32);
}
