/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/10 22:54:05 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"
#include "ft_list.h"
#include <stdlib.h>

void	ft_exit(const char *msg, int code)
{
	if (msg)
		ft_printf("%s\n", msg);
	exit(code);
}

void drawsqr(t_mlxdata *mlxdata, int x, int y, int z, int color, int width)
{
	t_vec3f pos = {(float)x + 1500.f, (float)y, (float)z};

	t_vec3f a1 = {(float)-width + pos.x, (float)-width + pos.y, 0.f + pos.z};
	t_vec3f a2 = {(float)width + pos.x, (float)-width + pos.y, 0.f + pos.z};
	t_vec3f a3 = {(float)width + pos.x, (float)width + pos.y, 0.f + pos.z};
	t_vec3f a4 = {(float)-width + pos.x, (float)width + pos.y, 0.f + pos.z};
	ft_drawline(mlxdata, a1, a2, color);
	ft_drawline(mlxdata, a2, a3, color);
	ft_drawline(mlxdata, a3, a4, color);
	ft_drawline(mlxdata, a4, a1, color);
}

int mousex = 0;
int mousey = 0;

int	key_callback(int keycode, t_mlxdata *mlxdata)
{
	ft_printf("%d %c\n", keycode, ft_keyascii(keycode, 0));
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
	drawsqr(mlxdata, mousex, mousey, 0, 0xffffff, 100);
	drawsqr(mlxdata, mousex, mousey, 1000, 0xff0000, 100);
	return (0);
}

int	mouse_callback(int button, int x, int y, t_mlxdata *mlxdata)
{
	static t_vec3f	old;
	t_vec3f			b;

	if (y < 0)
		return (0);
	(void)button;
	mousex = x;
	mousey = y;
	b.x = (float)x;
	b.y = (float)y;
	b.z = 1.f;
	if ((int)old.x != 0 && (int)old.y != 0)
		ft_drawline(mlxdata, old, b, rand() % 0xffffff);
	old = b;
	return (0);
}
#include <time.h>
#include <math.h>
int main(int argc, char **argv)
{
	t_model	*model;
	t_mlxdata	mlxdata;

	srand(time(NULL));
	if (!(mlxdata.ptr = mlx_init()))
		ft_exit("MLX failed to init", 1);
	if (!(mlxdata.win = mlx_new_window(mlxdata.ptr, 1000, 1000, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_key_hook(mlxdata.win, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	if (argc >= 2)
	{
		if ((model = ft_getmodel(argv[1])))
		{
			t_vec *translate = ft_vec_newn(3, 1500.f, 10.f, 0.f);
			t_vec *scale = ft_vec_newn(3, 50.f, 50.f, 3.f);
			ft_transform_model(model, ft_mat_mult(*ft_mat_translate(*translate), *ft_mat_scale(*scale), NULL));
			ft_printmodel(&mlxdata, model);
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
