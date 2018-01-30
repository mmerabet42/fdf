/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/31 00:02:18 by mmerabet         ###   ########.fr       */
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

int	key_callback(int keycode, void *param)
{
	(void)param;
	ft_printf("KEY : %d\n", keycode);
	if (keycode == K_ESC)
		ft_exit("Esc pressed !", 0);
	return (0);
}

int main()
{
	void	*mlxp;
	void	*winp;

	if (!(mlxp = mlx_init()))
		ft_exit("MLX failed to init", 1);
	if (!(winp = mlx_new_window(mlxp, 1000, 1000, "fdf")))
		ft_exit("Failed to create the window", 1);
	mlx_key_hook(winp, key_callback, NULL);
	mlx_loop(mlxp);
	mlx_destroy_window(mlxp, winp);
	return (0);
}
