/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_model.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:51:41 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/10 20:04:22 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"

void	ft_transform_model(t_model *model, t_mat *transform)
{
	static float	vector[] = {0.f, 0.f, 0.f};
	static t_vec	vec = {vector, 3};
	t_vec			*res;
	t_point			*p;
	t_vec3			i;

	if (!model || !transform)
		return ;
	i.x = 0;
	while (i.x < (int)model->width)
	{
		i.y = 0;
		while (i.y < (int)model->height)
		{
			p = ft_getpoint(model, i.x, i.y);
			vec.vector[0] = p->x;
			vec.vector[1] = p->y;
			vec.vector[2] = p->z;
			res = ft_mat_multv(*transform, vec, NULL);
			p->x = res->vector[0];
			p->y = res->vector[1];
			p->z = res->vector[2];
			++i.y;
		}
		++i.x;
	}
}
