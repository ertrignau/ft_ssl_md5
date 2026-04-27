/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:44:22 by eric              #+#    #+#             */
/*   Updated: 2026/04/27 15:05:25 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

void	init_md5_struct(t_md5 *md5)
{
	md5->A = 0x67452301;
	md5->B = 0xefcdab89;
	md5->C = 0x98badcfe;
	md5->D = 0x10325476;
	md5->bit_len = 0;
	md5->buffer_len = 0;
}

// Valeurs initiales SHA-256 (section 5.3.3 RFC 6234)
static const uint32_t sha256_h0[8] = {
	0x6a09e667,
	0xbb67ae85,
	0x3c6ef372,
	0xa54ff53a,
	0x510e527f,
	0x9b05688c,
	0x1f83d9ab,
	0x5be0cd19
};

void	init_sha256_struct(t_sha256 *sha256)
{
	for (int i = 0; i < 8; i++)
		sha256->state[i] = sha256_h0[i];
	sha256->bitlen = 0;
	sha256->bufferlen = 0;
}
