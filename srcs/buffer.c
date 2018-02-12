/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:03:25 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/12 18:44:28 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static int	*g_buffer;
static void	*imgptr;
static int	g_width;
static int	g_height;

void		ft_buffer_new(t_mlxdata *mlxdata, int width, int height)
{
	if (!mlxdata || !(imgptr = mlx_new_image(mlxdata->ptr, width, height)))
		return ;
	g_buffer = (int *)mlx_get_data_addr(imgptr, NULL, NULL, NULL);
	g_width = width;
	g_height = height;
}

int			*ft_buffer_at(int x, int y)
{
	if (!g_buffer)
		return (NULL);
	if (x < 0 || x >= g_width)
		x = 0;
	if (y < 0 || y >= g_height)
		y = 0;
	/*
	while (x < 0)
		x += g_width;
	while (x >= g_width)
		x -= g_width;
	while (y < 0)
		y += g_height;
	while (y >= g_height)
		y -= g_height;*/
	return (g_buffer + (x + g_width * y));
}

int			*ft_buffer_get(void)
{
	return (g_buffer);
}

void		ft_buffer_clear(void)
{
	int	size;
	int	i;

	if (!g_buffer)
		return ;
	size = g_width * g_height;
	i = 0;
	while (i < size)
		g_buffer[i++] = 0;
}

void		ft_buffer_put(t_mlxdata *mlxdata, int x, int y)
{
	if (!mlxdata || !g_buffer || !imgptr)
		return ;
	mlx_put_image_to_window(mlxdata->ptr, mlxdata->win, imgptr, x, y);
}
