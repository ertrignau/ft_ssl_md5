/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:15:44 by eric              #+#    #+#             */
/*   Updated: 2026/04/22 17:07:15 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

uint8_t	*md5_padding(char *msg, size_t len, size_t *new_len)
{
	uint8_t	*buffer;
	uint8_t	bits;
	size_t	j;

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
	bits = len * 8;
	ft_memcpy(buffer + *new_len - 8, &bits, 8);
	return (buffer);
}
