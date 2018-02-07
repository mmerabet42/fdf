/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/07 23:09:22 by mmerabet         ###   ########.fr       */
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

int	key_callback(int keycode, t_mlxdata *mlxdata)
{
	ft_printf("%d %c\n", keycode, ft_keyascii(keycode, 0));
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
	t_vec3 pos = {0, 0, 0};
	t_vec3 pos1 = {100, 100, 0};

	t_vec3 a1 = {200 + pos.x, 200 + pos.y, 0 + pos.z};
	t_vec3 a2 = {300 + pos.x, 200 + pos.y, 0 + pos.z};
	t_vec3 a3 = {300 + pos.x, 300 + pos.y, 0 + pos.z};
	t_vec3 a4 = {200 + pos.x, 300 + pos.y, 0 + pos.z};
	
	t_vec3 a5 = {200 + pos1.x, 200 + pos1.y, 20 + pos1.z};
	t_vec3 a6 = {300 + pos1.x, 200 + pos1.y, 20 + pos1.z};
	t_vec3 a7 = {300 + pos1.x, 300 + pos1.y, 20 + pos1.z};
	t_vec3 a8 = {200 + pos1.x, 300 + pos1.y, 20 + pos1.z};
	ft_drawline(mlxdata, a1, a2, 0xffffff);
	ft_drawline(mlxdata, a2, a3, 0xffffff);
	ft_drawline(mlxdata, a3, a4, 0xffffff);
	ft_drawline(mlxdata, a4, a1, 0xffffff);

	ft_drawline(mlxdata, a5, a6, 0xff0000);
	ft_drawline(mlxdata, a6, a7, 0xff0000);
	ft_drawline(mlxdata, a7, a8, 0xff0000);
	ft_drawline(mlxdata, a8, a5, 0xff0000);
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
	b.x = x;
	b.y = y;
	b.z = 1;
	if (old.x != 0 && old.y != 0)
		ft_drawline(mlxdata, old, b, rand() % 0xffffff);
	old = b;
	return (0);
}
#include <time.h>
int main()
{
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
