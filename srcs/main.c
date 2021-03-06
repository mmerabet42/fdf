/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/04/18 19:52:12 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"
#include "ft_list.h"
#include "ft_types.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

void	ft_exit(const char *msg, int code)
{
	if (msg)
		ft_printf("%s\n", msg);
	exit(code);
}

static int		mousex = 0;
static int		mousey = 0;
static t_model	*model;
//static t_mat	*projection;
//static t_mat	*view;
//static t_mat	*transform;
static t_mat	*rotmat;
static t_mat	*posmat;
static t_mat	*scalemat;
static t_vec	*position;
static t_vec	*rotation;
static t_vec	*scale;

int	key_callback(int keycode, t_mlxdata *mlxdata)
{
	(void)mlxdata;
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
	else if (keycode == K_PAD4)
		rotation->vector[1] += 1.f;
	else if (keycode == K_PAD6)
		rotation->vector[1] -= 1.f;
	else if (keycode == K_PAD2)
		rotation->vector[0] += 1.f;
	else if (keycode == K_PAD8)
		rotation->vector[0] -= 1.f;
	else if (keycode == K_PLUS)
		//ft_vec_addi(*scale, 1.f, scale);
		ft_zoom_set(ft_zoom_get() + 0.1f);
	else if (keycode == K_DASH)
	//	ft_vec_subi(*scale, 1.f, scale);
		ft_zoom_set(ft_zoom_get() - 0.1f);
	else if (keycode == K_LEFTARW)
		position->vector[0] -= 10.f;
	else if (keycode == K_RIGHTARW)
		position->vector[0] += 10.f;
	else if (keycode == K_UPARW)
		position->vector[1] -= 10.f;
	else if (keycode == K_DOWNARW)
		position->vector[1] += 10.f;
	if (keycode == K_PAD4 || keycode == K_PAD6 || keycode == K_PAD8 || keycode == K_PAD2
			|| keycode == K_PLUS || keycode == K_DASH
			|| keycode == K_LEFTARW || keycode == K_RIGHTARW
			|| keycode == K_UPARW || keycode == K_DOWNARW)
	{
		ft_printf("%f %f\n", position->vector[0], position->vector[1]);
		if (keycode == K_PAD4 || keycode == K_PAD6 || keycode == K_PAD8 || keycode == K_PAD2)
			rotmat = ft_mat_rotate(*rotation);
		else if (keycode == K_PLUS || keycode == K_DASH)
			scalemat = ft_mat_scale(*scale);
		else if (keycode == K_LEFTARW || keycode == K_RIGHTARW
				|| keycode == K_UPARW || keycode == K_DOWNARW)
			posmat = ft_mat_translate(*position);
	//	transform = ft_mat_mult(*ft_mat_mult(*projection, *view, transform), *ft_mat_mult(*posmat,
	//			*ft_mat_mult(*rotmat, *scalemat, transform), transform), transform);
	//	transform = ft_mat_mult(*posmat, *ft_mat_mult(*rotmat, *scalemat, transform), transform);
		ft_buffer_clear();
	//	ft_transform_model(model, transform);
		ft_printmodel(model);
		ft_buffer_put(mlxdata, 0, 0);
	}
	return (0);
}

int	mouse_callback(int button, int x, int y, t_mlxdata *mlxdata)
{
	static t_vec3f	old;
	t_vec3f			b;

	if (y < 0)
		return (0);
	(void)button;
	(void)mlxdata;
	mousex = x;
	mousey = y;
	b.x = (float)x;
	b.y = (float)y;
	b.z = 1.f;
	if ((int)old.x != 0 && (int)old.y != 0)
		ft_drawline(old, b, rand() % 0xffffff);
	old = b;
	ft_buffer_put(mlxdata, 0, 0);
	return (0);
}
/*
void	ft_hexcolorl(int color, unsigned char rgb[3])
{
	rgb[0] = (color & 0xff0000) >> (8 * 2);
	rgb[1] = (color & 0xff00) >> (8);
	rgb[2] = color & 0xff;
}
*/
#include <stdio.h>
#include <limits.h>
#include "ft_mem.h"
#include "ft_str.h"
int main(int argc, char **argv)
{
	t_mlxdata	mlxdata;

	srand(time(NULL));
	if (!(mlxdata.ptr = mlx_init()))
		ft_exit("MLX failed to init", 1);
	int winwidth = 1000;
	int winheight = 1000;
	if (!(mlxdata.win = mlx_new_window(mlxdata.ptr, winwidth, winheight, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_hook(mlxdata.win, 2, 1L << 0, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	if (argc >= 2)
	{
		ft_buffer_new(&mlxdata, winwidth, winheight);
	//	projection = ft_mat_perspective(10.f, (float)winwidth / (float)winheight, 0.1f, 100.f);
	//	view = ft_mat_lookat(*ft_vec_newn(3, 0.f, 0.f, 1.f),
	//			*ft_vec_newn(3, 0.f, 0.f, 0.f), *ft_vec_newn(3, 0.f, 0.f, 1.f));
	//	transform = ft_mat_new(4, 4);
		if ((model = ft_getmodel(argv[1])))
		{
		/*	size_t	x = 0, y = 0;
			t_point	*p;
			unsigned char rgb[3];
			while (y < model->height)
			{
				x = 0;
				while (x < model->width)
				{
					p = ft_getpoint(model, x, y);
					ft_hextorgb(p->color, rgb);
					ft_printf("%l{%d;%d;%d}%3.0f ", rgb[0], rgb[1], rgb[2], p->pos.z);
					++x;
				}
				ft_printf("\n");
				++y;
			}
			return (0);*/
		//	position = ft_vec_newn(3, 0.f, 0.f, 0.f);
		//	scale = ft_vec_newn(3, 10.f, 10.f, -5.f);
		//	rotation = ft_vec_newn(3, 0.f, 0.f, 0.f);
		//	posmat = ft_mat_translate(*position);
		//	rotmat = ft_mat_rotate(*rotation);
		//	scalemat = ft_mat_scale(*scale);
		//	transform = ft_mat_mult(*ft_mat_mult(*projection, *view, transform), *ft_mat_mult(*posmat,
		//		*ft_mat_mult(*rotmat, *scalemat, transform), transform), transform);
		//	transform = ft_mat_mult(*posmat, *ft_mat_mult(*rotmat, *scalemat, transform), transform);
		//	ft_transform_model(model, transform);
			ft_printmodel(model);
			ft_buffer_put(&mlxdata, 0, 0);
		}
		else
			ft_printf("Failed to create model\n");
	}
	else
		ft_printf("Usage: ./fdf <filename>\n");
	mlx_loop(mlxdata.ptr);
	mlx_destroy_window(mlxdata.ptr, mlxdata.win);
	return (0);
}
