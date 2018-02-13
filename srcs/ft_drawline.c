/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/13 22:02:56 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_matrix.h"
#include <math.h> 
#include <stdio.h>
#include "mlx.h"

static float	g_zoom = 1.f;

float	ft_zoom_get(void)
{
	return (g_zoom);
}

void	ft_zoom_set(float zoom)
{
	g_zoom = zoom;
}

static t_vec3f	ft_3dto2d(t_vec3f vec)
{
	return (vec);
	static float	cte = 0.5f;
	t_vec3f			res;

/*	res.x = cte * vec.x - cte * vec.y;
	res.y = vec.z + (cte / 2.0f) * vec.x + (cte / 2.0f) * vec.y;
*/	res.x = (vec.x * g_zoom) + cte * vec.z;
	res.y = (vec.y * g_zoom) + (cte / 2.f) * vec.z;
	res.z = -vec.z;
	return (res);
}

void			ft_drawline(t_vec3f a, t_vec3f b, int color)
{
	t_vec3f	d;
	t_vec3	s;
	t_vec3f	perr;

	a = ft_3dto2d(a);
	b = ft_3dto2d(b);
	d.x = ft_fabs(b.x - a.x);
	d.y = ft_fabs(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1: -1);
	perr.x = (d.x > d.y ? d.x : -d.y) / 2;
	while ((s.x == 1 ? a.x < b.x : b.x < a.x)
			|| (s.y == 1 ? a.y < b.y : b.y < a.y))
	{
		if (ft_buffer_get())
		{
			*ft_buffer_at((int)a.x, (int)a.y) = color;
		/*	*ft_buffer_at((int)a.x - 1, (int)a.y + g_zoom) = color;
			*ft_buffer_at((int)a.x + 1, (int)a.y) = color;
			*ft_buffer_at((int)a.x, (int)a.y - 1) = color;
			*ft_buffer_at((int)a.x, (int)a.y + 1) = color;*/
		}
		if ((perr.y = perr.x) > -d.x)
		{
			perr.x -= d.y;
			a.x += (float)s.x;
		}
		if (perr.y < d.y)
		{
			perr.x += d.x;
			a.y += (float)s.y;
		}
	}
}
