/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/06 21:46:18 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"
#include <math.h>
#include "mlx.h"

void	ft_drawline(t_mlxdata *mlxdata, t_vec3 a, t_vec3 b, int color)
{
	t_vec3	d;
	t_vec3	s;
	t_vec	*pos;
	int		err0;
	int		err1;

	pos = ft_3dto2d(a);
	a.x = pos->vector[0] / pos->vector[3];
	a.y = pos->vector[1] / pos->vector[3];
	pos = ft_3dto2d(b);
	b.x = pos->vector[0] / pos->vector[3];
	b.y = pos->vector[1] / pos->vector[3];
	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1 : -1);
	err0 = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(mlxdata->ptr, mlxdata->win, a.x, b.y, color);
		err1 = err0;
		if (err1 > -d.x)
		{
			err0 -= d.y;
			a.x += s.x;
		}
		if (err1 < d.y)
		{
			err0 += d.x;
			a.y += s.y;
		}
	}
}

#define G_FAR 100
#define G_NEAR 1
#define G_WIDTH 1000
#define G_HEIGHT 1000

t_vec	*ft_3dto2d(t_vec3 vec)
{
	t_vec	*pos = ft_vec_newn(4, vec.x, vec.y, vec.z, 1);
	t_mat	*ortho = ft_mat_newn(4, 4,
		1 / G_WIDTH, 0, 0, 0,
		0, 1 / G_HEIGHT, 0, 0,
		0, 0, -(2 / (G_FAR - G_NEAR)), -((G_FAR + G_NEAR) / (G_FAR - G_NEAR)),
		0, 0, 0, 1);
	
	ft_mat_multv(*ortho, *pos, pos);
	ft_mat_del(&ortho);
	return (pos);
}
