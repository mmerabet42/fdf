/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 15:26:45 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/11 22:08:57 by mmerabet         ###   ########.fr       */
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

static int mousex = 0;
static int mousey = 0;
static t_model	*model;
static t_mat	*transform;
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
	else if (keycode == K_LEFTARW)
		rotation->vector[2] += 1.f;
	else if (keycode == K_RIGHTARW)
		rotation->vector[2] -= 1.f;
	if (keycode == K_LEFTARW || keycode == K_RIGHTARW)
	{
		rotmat = ft_mat_rotate(*rotation);
		transform = ft_mat_mult(*posmat,
				*ft_mat_mult(*rotmat, *scalemat, NULL), NULL);
		ft_transform_model(model, transform);
		mlx_clear_window(mlxdata->ptr, mlxdata->win);
		ft_printmodel(mlxdata, model);
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
	mlx_key_hook(mlxdata.win, key_callback, &mlxdata);
	mlx_mouse_hook(mlxdata.win, mouse_callback, &mlxdata);
	if (argc >= 2)
	{
		if ((model = ft_getmodel(argv[1])))
		{
			position = ft_vec_newn(3, 1000.f, 0.f, 50.f);
			scale = ft_vec_newn(3, 50.f, 50.f, -20.f);
			rotation = ft_vec_newn(3, 0.f, 0.f, 45.f);
			posmat = ft_mat_translate(*position);
			rotmat = ft_mat_rotate(*rotation);
			scalemat = ft_mat_scale(*scale);
			transform = ft_mat_mult(*posmat,
					*ft_mat_mult(*rotmat, *scalemat, NULL), transform);
		/*	ft_transform_model(model, ft_mat_translate(*translate));
			ft_transform_model(model, ft_mat_rotate(*rotation));
			ft_transform_model(model, ft_mat_scale(*scale));*/
			ft_transform_model(model, transform);

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
