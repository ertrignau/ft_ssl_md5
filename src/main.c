/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:44:25 by eric              #+#    #+#             */
/*   Updated: 2026/04/22 17:05:59 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int main(int ac, char *av[])
{
	if (ac < 2)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	uint8_t *buffer;
	size_t len = ft_strlen(av[1]);
	size_t new_len;
	buffer = md5_padding(av[1], len, &new_len);
	if (!buffer)
		return (-1);
	printf("DEBUG: buffer = %p\n", buffer);
	for (size_t i = 0; i < new_len; i++)
		printf("%02x ", buffer[i]);
	printf("AFTER: buffer = %p\n", buffer);
	free(buffer);
	return (0);
}
