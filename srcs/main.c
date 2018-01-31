/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/31 19:24:59 by mmerabet         ###   ########.fr       */
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

int	key_callback(int keycode, t_mlxdata *param)
{
	(void)param;
	ft_printf("%d : %c\n", keycode, ft_keyascii(keycode, 1));
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
	return (0);
}

int	mouse_callback(int button, int x, int y, t_mlxdata *param)
{
	ft_printf("%d %d %d\n", button, x, y);
	mlx_pixel_put(param->mlx_ptr, param->win, x, y, 0xFFFFFF);
	return (0);
}

int main()
{
	ft_printf("%f\n", 7.0 / 4.0);
	t_mlxdata	mlxdata;

	if (!(mlxdata.mlx_ptr = mlx_init()))
		ft_exit("MLX failed to init", 1);
	if (!(mlxdata.win = mlx_new_window(mlxdata.mlx_ptr, 1000, 1000, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_key_hook(mlxdata.win, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	mlx_loop(mlxdata.mlx_ptr);
	mlx_destroy_window(mlxdata.mlx_ptr, mlxdata.win);
	return (0);
}
