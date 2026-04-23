/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:44:25 by eric              #+#    #+#             */
/*   Updated: 2026/04/23 15:35:09 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static void print_block(t_md5 ctx)
{
	for (int i = 0; i < 16; i++)
	{
		if (i < 4)
			printf("%02x", (ctx.A >> (8 * i)) & 0xff);
		else if (i < 8)
			printf("%02x", (ctx.B >> (8 * (i - 4))) & 0xff);
		else if (i < 12)
			printf("%02x", (ctx.C >> (8 * (i - 8))) & 0xff);
		else
			printf("%02x", (ctx.D >> (8 * (i - 12))) & 0xff);
	}
}

int main(int ac, char *av[])
{
	t_md5 	ctx;
	uint8_t	*buffer;
	size_t	len;
	size_t	new_len;
	
	if (ac < 2)
	{
		printf("Not enough arguments\n");
		return (1);
	}
	len = ft_strlen(av[1]);
	buffer = md5_padding(av[1], len, &new_len);
	if (!buffer)
		return (1);
	init_md5_struct(&ctx);
	for (size_t i = 0; i < new_len; i += 64)
		md5_process_block(buffer + i, &ctx);
	print_block(ctx);
	printf("\n");
	free(buffer);
	return (0);
}
