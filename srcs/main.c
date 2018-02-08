/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/08 21:42:34 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	ft_exit(const char *msg, int code)
{
	if (msg)
		ft_printf("%s\n", msg);
	exit(code);
}

void drawsqr(t_mlxdata *mlxdata, int x, int y, int z, int color)
{
	t_vec3 pos = {x, y, z};

	t_vec3 a1 = {-100 + pos.x, -100 + pos.y, 0 + pos.z};
	t_vec3 a2 = {100 + pos.x, -100 + pos.y, 0 + pos.z};
	t_vec3 a3 = {100 + pos.x, 100 + pos.y, 0 + pos.z};
	t_vec3 a4 = {-100 + pos.x, 100 + pos.y, 0 + pos.z};
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
	drawsqr(mlxdata, mousex + 1500, mousey, 0, 0xffffff);
	drawsqr(mlxdata, mousex + 1500, mousey, 1000, 0xff0000);
	return (0);
}

int	mouse_callback(int button, int x, int y, t_mlxdata *mlxdata)
{
/*	void	*img;
	char	*imgdata;
	int		bits;
	int		lsize;
	int		endian;

	img = mlx_new_image(mlxdata->ptr, 10, 10);
	imgdata = mlx_get_data_addr(mlxdata->ptr, &bits, &lsize, &endian);
	imgdata[10] = (char)255;
	imgdata[11] = (char)255;
	imgdata[12] = (char)255;
	mlx_put_image_to_window(mlxdata->ptr, mlxdata->win, img, x, y);
	mlx_destroy_image(mlxdata->ptr, img);
	ft_printf("L: %d %d\n", bits, lsize);
	return (0);*/
	static t_vec3	old;
	t_vec3			b;

	if (y < 0)
		return (0);
	(void)button;
	mousex = x;
	mousey = y;
	b.x = x;
	b.y = y;
	b.z = 1;
	if (old.x != 0 && old.y != 0)
		ft_drawline(mlxdata, old, b, rand() % 0xffffff);
	old = b;
	return (0);
}
#include <time.h>
#include "ft_types.h"
int main(int argc, char **argv)
{
	t_model	*model;

	if (argc >= 2)
	{
		if ((model = ft_getmodel(argv[1])))
		{
			ft_printf("Yes success\n");
		}
		else
			ft_printf("Failed to create model\n");
	}
	else
		ft_printf("usage: ./fdf [map files ...]\n");
	return (0);
	t_mlxdata	mlxdata;

	srand(time(NULL));
	if (!(mlxdata.ptr = mlx_init()))
		ft_exit("MLX failed to init", 1);
	if (!(mlxdata.win = mlx_new_window(mlxdata.ptr, 1000, 1000, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_key_hook(mlxdata.win, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	mlx_loop(mlxdata.ptr);
	mlx_destroy_window(mlxdata.ptr, mlxdata.win);
	return (0);
}
