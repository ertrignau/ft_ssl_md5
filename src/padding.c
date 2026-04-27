/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:15:44 by eric              #+#    #+#             */
/*   Updated: 2026/04/27 16:30:34 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t	*md5_padding(char *msg, size_t len, size_t *new_len)
{
	uint8_t		*buffer;
	uint64_t	bits;
	size_t		j;

	*new_len = len + 1;
	while (*new_len % 64 != 56)
		(*new_len)++;
	*new_len += 8;
	buffer = malloc(*new_len);
	if (!buffer)
		return (NULL);
	for (size_t i = 0; i < len; i++) // -> copier le msg dans le buffer
		buffer[i] = msg[i];
	buffer[len] = 0x80;
	for (j = len + 1; j < *new_len - 8; j++) // -> remplir le reste de 0
		buffer[j] = 0;
	bits = (uint64_t) len * 8;
	for (int i = 0; i < 8; i++)
		buffer[*new_len - 8 + i] = (bits >> (8 * i)) & 0xff;
	return (buffer);
}

uint8_t	*sha256_padding(char *msg, size_t len, size_t *new_len)
{
	uint8_t		*buffer;
	uint64_t	bit_len = len * 8;
	
	*new_len = len + 1;
	while (*new_len % 64 != 56)
		(*new_len)++;
	buffer = malloc(*new_len + 8);
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, msg, len);
	buffer[len] = 0x80;
	ft_memset(buffer + len + 1, 0, *new_len - len - 1);
	for (int i = 0; i < 8; i++)
		buffer[*new_len + i] = (bit_len >> (56 - 8 *i)) & 0xff;
	*new_len += 8;
	return (buffer);
}
