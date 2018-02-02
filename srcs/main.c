/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 23:13:09 by mmerabet         ###   ########.fr       */
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
/*	t_vec	*veca = ft_vec_newn(3, 1, 1, 1);
	t_vec	*vecb = ft_vec_newn(3, 1, 1, 1);
	ft_vec_addi(*veca, 5, veca);
	ft_vec_addi(*vecb, 10, vecb);
	t_vec	*vecc = ft_vec_mult(*veca, *vecb, NULL);
	ft_vec_dump(veca);
	ft_vec_dump(vecb);
	ft_vec_dump(vecc);
	ft_vec_del(&veca);
	ft_vec_del(&vecb);
	ft_vec_del(&vecc);
	return (0);*/
	t_mat	*mata = ft_mat_newi(4, 4, 1);
	ft_mat_addi(*mata, 5, mata);
	t_mat	*matb = ft_mat_newn(4, 4,
			1, 2, 3, 4,
			5, 6, 7, 8,
			9, 10, 11, 12,
			13, 14, 15, 16);
	ft_mat_dump(mata);
	ft_printf("\n");
	ft_mat_dump(matb);
	ft_printf("\n");
	ft_mat_mult(*mata, *matb, mata);
	ft_mat_dump(mata);

	ft_mat_del(&mata);
	ft_mat_del(&matb);
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
