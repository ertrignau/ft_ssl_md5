/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:13:53 by eric              #+#    #+#             */
/*   Updated: 2026/04/24 15:15:24 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

int md5_engine(int ac, char **av)
{
	int	i;
	
	i = 2;
	if (ac == 2)
	{
		read_stdin();
		return (0);
	}
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-s") == 0)
		{
			i++;
			if (i < ac)
				md5_string(av[i]);
		}
		else if (ft_strcmp(av[i], "-p") == 0)
			read_stdin();
		else
			md5_string(av[i]); // file ou string simple (phase 1)
		i++;
	}
	return (0);
}