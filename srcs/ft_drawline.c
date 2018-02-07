/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/07 18:13:58 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"
#include <math.h>
#include "ft_printf.h"
#include "mlx.h"

void	ft_drawline(t_mlxdata *mlxdata, t_vec3 a, t_vec3 b, int color)
{
	t_vec3	d;
	t_vec3	s;
	float	err0;
	float	err1;

//	ft_3dto2d(&a);
//	ft_3dto2d(&b);
	d.x = ft_fabs(b.x - a.x);
	d.y = ft_fabs(b.y - a.y);
	s.x = (a.x < b.x ? 1.f : -1.f);
	s.y = (a.y < b.y ? 1.f : -1.f);
	err0 = (d.x > d.y ? d.x : -d.y) / 2.f;
	while (a.x != b.x || a.y != b.y)
	{
		ft_printf("LOL: %d %d\n", (int)a.x, (int)a.y);
		mlx_pixel_put(mlxdata->ptr, mlxdata->win, (int)a.x, (int)b.y, color);
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

#define WIDTH 1000
#define HEIGHT 1000

void	ft_3dto2d(t_vec3 *vec)
{
	float	halfw = WIDTH / 2;
	float	halfh = HEIGHT / 2;

	vec->x = (+(vec->x / (vec->z ? vec->z : 1)) + halfw) * halfw;
	vec->y = (-(vec->y / (vec->z ? vec->z : 1)) + halfh) * halfh;
}
