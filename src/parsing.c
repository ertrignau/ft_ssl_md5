/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:44:27 by eric              #+#    #+#             */
/*   Updated: 2026/04/24 15:16:08 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void print_help()
{
	printf("Usage: ft_ssl [algo] [flags] [file/string/stdin]\n");
	printf("Algo: md5 or sha256\n");
	printf("Flags: -p -q -r -s -h\n");
}

int	parse_arguments(int ac, char *av[], t_env *env)
{
	
	if (ac < 2)
	{
		fprintf(stderr, "Error not enough arguments\n");
		print_help();
		return (1);
	}
	if (ft_strcmp(av[1], "md5") == 0)
		env->algo = MD5;
	else if (ft_strcmp(av[1], "sha256") == 0)
		env->algo = SHA256;
	else
	{
		fprintf(stderr, "Error: wrong algorithm %s doesn't exist\n", av[1]);
		print_help();
		return (1);	
	}
	return (0);
}
