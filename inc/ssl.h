/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:43:48 by eric              #+#    #+#             */
/*   Updated: 2026/04/23 15:37:28 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
#define SSL_H

#define F(B, C, D) (((B) & (C)) | (~(B) & (D)))
#define G(B, C, D) (((B) & (D)) | ((C) & ~(D)))
#define H(B, C, D) ((B) ^ (C) ^ (D))
#define I(B, C, D) ((C) ^ ((B) | ~(D)))
#define LEFTROTATE(x,s) (((x) << (s)) | ((x) >> (32 - (s))))

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
} t_md5;

/*INIT*/
void	init_md5_struct(t_md5 *md5);

/*PARSING*/

/*PADDING*/
uint8_t		*md5_padding(char *msg, size_t len, size_t *new_len);

/*ALGO*/
void		block_to_word(uint8_t *block, uint32_t M[16]);
void		md5_process_block(uint8_t *block, t_md5 *ctx);

/*UTILS*/

#endif