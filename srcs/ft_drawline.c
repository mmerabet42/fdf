/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/02 19:15:32 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"
#include "mlx.h"

void	ft_drawline(t_mlxdata *mlxdata, t_vec2 a, t_vec2 b, int color)
{
	t_vec3	d;
	t_vec3	s;
	int		err0;
	int		err1;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1 : -1);
	err0 = (d.x > d.y ? d.x : -d.y) / 2;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(mlxdata->mlx_ptr, mlxdata->win, a.x, a.y, color);
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
