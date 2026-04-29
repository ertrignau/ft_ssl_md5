/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:15:23 by eric              #+#    #+#             */
/*   Updated: 2026/04/29 15:40:33 by eric             ###   ########.fr       */
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

void	print_sha256(t_sha256 ctx)
{
    for (int i = 0; i < 8; i++)
        printf("%08x", ctx.state[i]);
    printf("\n");
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

char *open_file(const char *filename)
{
	char	buffer[1024];
	int		fd;
	size_t	total;
	ssize_t	r;
	char	*content;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	total = 0;
	content = NULL;
	while ((r = read(fd, buffer, 1024)) > 0)
	{
		char *new = malloc(total + r + 1);
		if (!new)
			return (NULL);
		if (content)
		{
			ft_memcpy(new, content, total);
			free(content);
		}
		ft_memcpy(new + total, buffer, r);
		total += r;
		content = new;
	}
	close (fd);
	if (content)
		content[total] = '\0';
	return (content);
}
