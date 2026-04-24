/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:15:23 by eric              #+#    #+#             */
/*   Updated: 2026/04/24 15:46:06 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	print_md5(t_md5 ctx)
{
	uint32_t tab[4] = {ctx.A, ctx.B, ctx.C, ctx.D};

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			printf("%02x", (tab[i] >> (8 * j)) & 0xff);
	printf("\n");
}

void	md5_string(char *str)
{
	t_md5 	ctx;
	uint8_t	*buffer;
	size_t	len;
	size_t new_len;

	len = ft_strlen(str);
	buffer = md5_padding(str, len, &new_len);
	if (!buffer)
		return ;
	init_md5_struct(&ctx);
	for (size_t i = 0; i < new_len; i += 64)
		md5_process_block(buffer + i, &ctx);
	print_md5(ctx);
	free (buffer);
}

char	*read_stdin()
{
	char	buffer[1024];
	char	*input;
	size_t	r;
	size_t	total;

	input = NULL;
	total = 0;

	while ((r = read(0, buffer, 1024)) > 0)
	{
		char *new = malloc(total + r + 1);
		if (!new)
			return (NULL);
		if (input)
		{
			ft_memcpy(new, input, total);
			free(input);
		}
		ft_memcpy(new + total, buffer, r);
		total += r;
		input = new;
	}
	if (input)
		input[total]= '\0';
	return (input);
}