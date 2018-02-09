/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/09 22:36:30 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_matrix.h"
#include <math.h> 
#include "ft_printf.h"
#include "mlx.h"

static t_vec3	ft_3dto2d(t_vec3 vec)
{
	static float	cte = 0.5;
	t_vec3			res;

	res.x = cte * vec.x - cte * vec.y;
	res.y = vec.z + (cte / 2.0) * vec.x + (cte / 2.0) * vec.y;
	/*res.x = vec.x + CTE1 * vec.z;
	res.y = vec.y + (CTE1 / 2) * vec.z;*/
	res.z = 0;
	return (res);
}

void			ft_drawline(t_mlxdata *mlxdata, t_vec3 a, t_vec3 b, int color)
{
	t_vec3	d;
	t_vec3	s;
	t_vec2	perr;

	a = ft_3dto2d(a);
	b = ft_3dto2d(b);
	d.x = ft_fabs(b.x - a.x);
	d.y = ft_fabs(b.y - a.y);
	s.x = (a.x < b.x ? 1.f : -1.f);
	s.y = (a.y < b.y ? 1.f : -1.f);
	perr.x = (d.x > d.y ? d.x : -d.y) / 2.f;
	while (a.x != b.x || a.y != b.y)
	{
		mlx_pixel_put(mlxdata->ptr, mlxdata->win, (int)a.x, (int)a.y, color);
		if ((perr.y = perr.x) > -d.x)
		{
			perr.x -= d.y;
			a.x += s.x;
		}
		if (perr.y < d.y)
		{
			perr.x += d.x;
			a.y += s.y;
		}
	}
}
