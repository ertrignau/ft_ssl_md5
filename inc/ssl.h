/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eric <eric@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 14:43:48 by eric              #+#    #+#             */
/*   Updated: 2026/04/27 17:18:26 by eric             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSL_H
#define SSL_H

#define F(B, C, D) (((B) & (C)) | (~(B) & (D)))
#define G(B, C, D) (((B) & (D)) | ((C) & ~(D)))
#define H(B, C, D) ((B) ^ (C) ^ (D))
#define I(B, C, D) ((C) ^ ((B) | ~(D)))
#define LEFTROTATE(x,s) (((x) << (s)) | ((x) >> (32 - (s))))

#define ROTR(x,n) ((x >> n) | (x << (32 - n)))
#define SHR(x,n)  (x >> n)
#define CH(x,y,z)  ((x & y) ^ (~x & z))
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z))
#define SIG0(x) (ROTR(x,7) ^ ROTR(x,18) ^ SHR(x,3))
#define SIG1(x) (ROTR(x,17) ^ ROTR(x,19) ^ SHR(x,10))
#define SUM0(x) (ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22))
#define SUM1(x) (ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25))

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

typedef enum e_algo
{
    MD5,
    SHA256
} t_algo;

typedef struct s_env
{
    t_algo  algo;
} t_env;

typedef struct s_md5
{
	uint32_t	A;
	uint32_t	B;
	uint32_t	C;
	uint32_t	D;
	uint64_t	bit_len;
	size_t		buffer_len;
} t_md5;

typedef struct	s_sha256
{
	uint32_t	state[8]; // A B C D E F G H
	uint64_t	bitlen;
	size_t		bufferlen;
} t_sha256;

/*INIT*/
void		init_md5_struct(t_md5 *md5);
void		init_sha256_struct(t_sha256 *sha256);

/*PARSING*/
void		print_help();
int			parse_arguments(int ac, char *av[], t_env *env);

/*PADDING*/
uint8_t		*md5_padding(char *msg, size_t len, size_t *new_len);
uint8_t		*sha256_padding(char *msg, size_t len, size_t *new_len);

/*ALGO MD5*/
void		block_to_word(uint8_t *block, uint32_t M[16]);
void		md5_process_block(uint8_t *block, t_md5 *ctx);
void		md5_string(char *str);

/*ALGO SHA256*/
void		sha256_process_block(uint8_t *block, t_sha256 *sha256);
void		sha256_string(char *str);

/*ENGINE*/
// int 		md5_engine(int ac, char **av);
int			engine(t_env *env, int ac, char *av[]);

/*UTILS*/
char		*read_stdin();
void		print_md5(t_md5 ctx);
void 		print_sha256(t_sha256 ctx);

#endif