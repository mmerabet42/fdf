/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 23:49:07 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/31 19:10:25 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static t_keypair	g_asciicode[] = {
	{K_A, 'a'}, {K_B, 'b'}, {K_C, 'c'}, {K_D, 'd'}, {K_E, 'e'}, {K_F, 'f'},
	{K_G, 'g'}, {K_H, 'h'}, {K_I, 'i'}, {K_J, 'j'}, {K_K, 'k'}, {K_L, 'l'},
	{K_M, 'm'}, {K_N, 'n'}, {K_O, 'o'}, {K_P, 'p'}, {K_Q, 'q'}, {K_R, 'r'},
	{K_S, 's'}, {K_T, 't'}, {K_U, 'u'}, {K_V, 'v'}, {K_W, 'w'}, {K_X, 'x'},
	{K_Y, 'y'}, {K_Z, 'z'}, {K_0, '0'}, {K_1, '1'}, {K_2, '2'}, {K_3, '3'},
	{K_4, '4'}, {K_5, '5'}, {K_6, '6'}, {K_7, '7'}, {K_8, '8'}, {K_9, '9'},
	{K_UNDERSCORE, '-'}, {K_EQUAL, '='}, {K_DELETE, '\b'}, {K_TAB, '\t'},
	{K_L_BRAC, '['}, {K_R_BRAC, ']'}, {K_BACKSLASH, '\\'}, {K_SEMICOLON, ';'},
	{K_QUOTE, '\''}, {K_COMMA, ','}, {K_DOT, '.'}, {K_SLASH, '/'},
	{K_TILDE, '`'}, {K_PAD_EQUAL, '='}, {K_PAD_SLASH, '/'}, {K_STAR, '*'},
	{K_DASH, '-'}, {K_PLUS, '+'}, {K_PAD_DOT, '.'}, {K_PAD0, '0'},
	{K_PAD1, '1'}, {K_PAD2, '2'}, {K_PAD3,'3'}, {K_PAD4, '4'}, {K_PAD5, '5'},
	{K_PAD6, 'x'}, {K_PAD7, '7'}, {K_PAD8, '8'}, {K_PAD9, '9'}, {K_SPACE, ' '},
	{K_RETURN, '\n'}, {K_ENTER, '\n'}
};

static t_keypair	g_asciimaj[] = {
	{K_A, 'A'}, {K_B, 'B'}, {K_C, 'C'}, {K_D, 'D'}, {K_E, 'E'}, {K_F, 'F'},
	{K_G, 'G'}, {K_H, 'H'}, {K_I, 'I'}, {K_J, 'J'}, {K_K, 'K'}, {K_L, 'L'},
	{K_M, 'M'}, {K_N, 'N'}, {K_O, 'O'}, {K_P, 'P'}, {K_Q, 'Q'}, {K_R, 'R'},
	{K_S, 'S'}, {K_T, 'T'}, {K_U, 'U'}, {K_V, 'V'}, {K_W, 'W'}, {K_X, 'X'},
	{K_Y, 'Y'}, {K_Z, 'Z'}, {K_0, ')'}, {K_1, '!'}, {K_2, '@'}, {K_3, '#'},
	{K_4, '$'}, {K_5, '%'}, {K_6, '^'}, {K_7, '&'}, {K_8, '*'}, {K_9, '('},
	{K_UNDERSCORE, '_'}, {K_EQUAL, '+'}, {K_DELETE, '\b'}, {K_TAB, '\t'},
	{K_L_BRAC, '{'}, {K_R_BRAC, '}'}, {K_BACKSLASH, '|'}, {K_SEMICOLON, ':'},
	{K_QUOTE, '"'}, {K_COMMA, '<'}, {K_DOT, '>'}, {K_SLASH, '?'},
	{K_TILDE, '~'}, {K_PAD_EQUAL, '='}, {K_PAD_SLASH, '/'}, {K_STAR, '*'},
	{K_DASH, '-'}, {K_PLUS, '+'}, {K_PAD_DOT, '.'}, {K_PAD0, '0'},
	{K_PAD1, '1'}, {K_PAD2, '2'}, {K_PAD3,'3'}, {K_PAD4, '4'}, {K_PAD5, '5'},
	{K_PAD6, 'x'}, {K_PAD7, '7'}, {K_PAD8, '8'}, {K_PAD9, '9'}, {K_SPACE, ' '},
	{K_RETURN, '\n'}, {K_ENTER, '\n'}
};
size_t				g_asciilen = sizeof(g_asciicode) / sizeof(t_keypair);

char	ft_keyascii(int keycode, int maj)
{
	size_t	i;

	i = 0;
	while (i < g_asciilen)
	{
		if (keycode == g_asciicode[i].keycode)
				return (maj ? g_asciimaj[i].ascii : g_asciicode[i].ascii);
		++i;
	}
	return (0);
}
