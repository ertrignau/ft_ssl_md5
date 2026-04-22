/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:43:48 by eric              #+#    #+#             */
/*   Updated: 2026/04/22 17:02:55 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
#define SSL_H

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

typedef struct s_md5
{
	uint32_t	A;
	uint32_t	B;
	uint32_t	C;
	uint32_t	D;
	uint64_t	bit_len;
	size_t		buffer_len;
	uint8_t		buffer[64];
} t_md5;

/*INIT*/
void	init_md5_struct(t_md5 *md5);

/*PARSING*/

/*PADDING*/
uint8_t	*md5_padding(char *msg, size_t len, size_t *new_len);
/*ALGO*/

/*UTILS*/

#endif