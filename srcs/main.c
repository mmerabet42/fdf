/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/03 22:43:30 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
/*
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
	static t_vec2	old;
	t_vec2			b;

	b.x = x;
	b.y = y;
	ft_printf("%d %d %d\n", button, x, y);
	if (old.x != 0 && old.y != 0)
		ft_drawline(mlxdata, old, b, 0xFFFFFF);
	old = b;
	return (0);
}
*/

int main()
{
	t_mat	*mata = ft_mat_newn(2, 3,
			1, -1, 2,
			0, -3, 1);
	t_vec	*veca = ft_vec_newn(3, 2, 1, 0);
	ft_mat_dump(mata);
	ft_printf("\n\n");
	ft_vec_dump(veca);
	ft_mat_multv(*mata, *veca, veca);
	ft_printf("\n\n");
	ft_vec_dump(veca);
	ft_mat_del(&mata);
	ft_vec_del(&veca);
//	ft_vec_del(&vecb);
	return (0);
/*	t_mlxdata	mlxdata;

	if (!(mlxdata.mlx_ptr = mlx_init()))
		ft_exit("MLX failed to init", 1);
	if (!(mlxdata.win = mlx_new_window(mlxdata.mlx_ptr, 1000, 1000, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_key_hook(mlxdata.win, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	mlx_loop(mlxdata.mlx_ptr);
	mlx_destroy_window(mlxdata.mlx_ptr, mlxdata.win);
	return (0);*/
}
