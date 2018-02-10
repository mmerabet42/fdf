/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/10 19:57:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_matrix.h"
#include <math.h> 
#include "ft_printf.h"
#include "mlx.h"

static t_vec3f	ft_3dto2d(t_vec3f vec)
{
	static float	cte = 0.4f;
	t_vec3f			res;

	res.x = cte * vec.x - cte * vec.y;
	res.y = vec.z + (cte / 2.0f) * vec.x + (cte / 2.0f) * vec.y;
	/*res.x = vec.x + CTE1 * vec.z;
	res.y = vec.y + (CTE1 / 2) * vec.z;*/
	res.z = 0;
	return (res);
}

void			ft_drawline(t_mlxdata *mlxdata, t_vec3f a, t_vec3f b, int color)
{
	t_vec3f	d;
	t_vec3	s;
	t_vec2	perr;

	a = ft_3dto2d(a);
	b = ft_3dto2d(b);
	d.x = ft_fabs(b.x - a.x);
	d.y = ft_fabs(b.y - a.y);
	s.x = (a.x < b.x ? 1.f : -1.f);
	s.y = (a.y < b.y ? 1.f : -1.f);
	perr.x = (d.x > d.y ? d.x : -d.y) / 2.f;
	while ((s.x == 1.f ? a.x < b.x : b.x < a.x)
			|| (s.y == 1.f ? a.y < b.y : b.y < a.y))
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
