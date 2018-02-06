/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/06 21:46:25 by mmerabet         ###   ########.fr       */
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
	(void)mlxdata;
	ft_printf("%d : %c\n", keycode, ft_keyascii(keycode, 1));
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
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
	static int		scrolli;
	t_vec3			b;

	b.x = x;
	b.y = y;
	b.z = 2;
	ft_printf("%d %d %d %d\n", button, x, y, scrolli);
	if (old.x != 0 && old.y != 0)
		ft_drawline(mlxdata, old, b, rand() % 0xFFFFFF);
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
