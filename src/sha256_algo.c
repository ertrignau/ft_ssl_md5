/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 12:11:38 by eric              #+#    #+#             */
/*   Updated: 2026/04/27 17:22:12 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ssl.h"

static const uint32_t K[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

static void	block_to_word_sha256(uint8_t *block, uint32_t W[16])
{
	for (size_t i = 0; i < 16; i++)
	{
		W[i] = ((uint32_t)block[i * 4] << 24)
			| ((uint32_t)block[i * 4 + 1] << 16)
			| ((uint32_t)block[i * 4 + 2] << 8)
			| (uint32_t)block[i * 4 + 3];
	}
}

void	sha256_process_block(uint8_t *block, t_sha256 *sha256)
{
	uint32_t	W[64];
	uint32_t	a,b,c,d,e,f,g,h;
	uint32_t	T1, T2;

	block_to_word_sha256(block, W);
	for (int i = 16; i < 64; i++)
		W[i] = SIG1(W[i-2]) + W[i-7] + SIG0(W[i-15]) + W[i-16];

	a = sha256->state[0];
	b = sha256->state[1];
	c = sha256->state[2];
	d = sha256->state[3];
	e = sha256->state[4];
	f = sha256->state[5];
	g = sha256->state[6];
	h = sha256->state[7];

	for (int i = 0; i < 64; i++)
	{
		T1 = h + SUM1(e) + CH(e, f, g) + K[i] + W[i];
		T2 = SUM0(a) + MAJ(a, b, c);

		h = g;
		g = f;
		f = e;
		e = d + T1;
		d = c;
		c = b;
		b = a;
		a = T1 + T2;
	}
	sha256->state[0] += a;
	sha256->state[1] += b;
	sha256->state[2] += c;
	sha256->state[3] += d;
	sha256->state[4] += e;
	sha256->state[5] += f;
	sha256->state[6] += g;
	sha256->state[7] += h;
}

void	sha256_string(char *str)
{
	t_sha256 sha256;
	uint8_t *buffer;
	size_t len;
	size_t new_len;

	len = ft_strlen(str);
	buffer = sha256_padding(str, len, &new_len);
	if (!buffer)
        return;
	init_sha256_struct(&sha256);
    for (size_t i = 0; i < new_len; i += 64)
        sha256_process_block(buffer + i, &sha256);
    print_sha256(sha256);
    free(buffer);
}