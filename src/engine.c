/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 15:13:53 by eric              #+#    #+#             */
/*   Updated: 2026/04/28 15:47:10 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static t_hash_func g_hash_funcs[2] = {
	md5_string,
	sha256_string
};

t_flag_map g_flags[] = {
	{"-p", handle_p},
	{"-s", handle_s},
	{NULL, NULL}
};

void	handle_p(t_env *env, char *av[], int *i)
{
	(void)av;
	(void)i;
	char *input = read_stdin();
	if (input)
	{
		g_hash_funcs[env->algo](input);
		free(input);
	}
}

void	handle_s(t_env *env, char *av[], int *i)
{
	(*i)++;
	if (av[*i])
	{
		env->s = 1;
		g_hash_funcs[env->algo](av[*i]);
	}
}

void	handle_default(t_env *env, char *av)
{
	g_hash_funcs[env->algo](av);
}

int		dispatch_flag(t_env *env, char *av[], int *i)
{
	int j = 0;
	
	while (g_flags[j].flag)
	{
		if (!ft_strcmp(av[*i], g_flags[j].flag))
		{
			g_flags[j].func(env, av, i);
			return (1);
		}
		j++;
	}
	return (0);
}

int engine(t_env *env, int ac, char *av[])
{
	int i = 2;
	
	if (ac == 2)
	{
		handle_p(env, av, &i); // stdin only
		return (0);
	}
	
	while (i < ac)
	{
		if (av[i][0] == '-' && dispatch_flag(env, av, &i))
		{
			i++;
			continue;
		}
		handle_default(env, av[i]);
		i++;
	}
	return (0);
}