/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:36:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/06 21:46:23 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define K_ESC 53
# define K_ENTER 36
# define K_RETURN 76
# define K_SPACE 49
# define K_Q 12
# define K_W 13
# define K_E 14
# define K_R 15
# define K_T 17
# define K_Y 16
# define K_U 32
# define K_I 34
# define K_O 31
# define K_P 35
# define K_A 0
# define K_S 1
# define K_D 2
# define K_F 3
# define K_G 5
# define K_H 4
# define K_J 38
# define K_K 40
# define K_L 37
# define K_Z 6
# define K_X 7
# define K_C 8
# define K_V 9
# define K_B 11
# define K_N 45
# define K_M 46
# define K_1 18
# define K_2 19
# define K_3 20
# define K_4 21
# define K_5 23
# define K_6 22
# define K_7 26
# define K_8 28
# define K_9 25
# define K_0 29
# define K_UNDERSCORE 27
# define K_EQUAL 24
# define K_DELETE 51
# define K_TAB 48
# define K_CAPS 272
# define K_L_SHIFT 257
# define K_L_CTRL 256
# define K_L_OPT 261
# define K_L_CMD 259
# define K_R_CMD 260
# define K_R_OPT 262
# define K_R_CTRL 269
# define K_R_SHIFT 258
# define K_L_BRAC 33
# define K_R_BRAC 30
# define K_BACKSLASH 42
# define K_SEMICOLON 41
# define K_QUOTE 39
# define K_COMMA 43
# define K_DOT 47
# define K_SLASH 44
# define K_TILDE 50
# define K_FN 279
# define K_HOME 115
# define K_PAGEUP 116
# define K_PAGEDOWN 121
# define K_DELETE2 117
# define K_END 119
# define K_F1 122
# define K_F2 120
# define K_F3 99
# define K_F4 118
# define K_F5 96
# define K_F6 97
# define K_F7 98
# define K_F8 100
# define K_F9 101
# define K_F10 109
# define K_F12 111
# define K_F13 105
# define K_F14 107
# define K_F15 113
# define K_F16 106
# define K_F17 64
# define K_F18 79
# define K_F19 80
# define K_LEFTARW 123
# define K_RIGHTARW 124
# define K_UPARW 126
# define K_DOWNARW 125
# define K_CLEAR 71
# define K_PAD_EQUAL 81
# define K_PAD_SLASH 75
# define K_STAR 67
# define K_DASH 78
# define K_PLUS 69
# define K_PAD_DOT 65
# define K_PAD0 82
# define K_PAD1 83
# define K_PAD2 84
# define K_PAD3 85
# define K_PAD4 86
# define K_PAD5 87
# define K_PAD6 88
# define K_PAD7 89
# define K_PAD8 91
# define K_PAD9 92

# define M_LEFT 1
# define M_RIGHT 2
# define M_WHEELUP 5
# define M_WHEELDOWN 4
# define M_WHEELLEFT 7
# define M_WHEELRIGHT 6

# include "ft_math.h"

typedef struct	s_mlxdata
{
	void		*ptr;
	void		*win;
}				t_mlxdata;

typedef struct	s_keypair
{
	int			keycode;
	char		ascii;
}				t_keypair;

char	ft_keyascii(int keycode, int maj);

void	ft_drawline(t_mlxdata *mlxdata, t_vec3 a, t_vec3 b, int color);
t_vec	*ft_3dto2d(t_vec3 vec);

#endif
