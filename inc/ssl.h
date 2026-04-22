/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:43:48 by eric              #+#    #+#             */
/*   Updated: 2026/04/22 15:12:28 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
#define SSL_H

#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

typedef struct s_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint64_t	bit_len;
	uint8_t		buffer[64];
} t_md5;

/*INIT*/

/*PARSING*/

/*PADDING*/

/*ALGO*/

/*UTILS*/

#endif