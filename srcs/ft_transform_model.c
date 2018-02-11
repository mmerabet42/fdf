/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_model.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:51:41 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/11 21:07:29 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"

void	ft_transform_model(t_model *model, t_mat *transform)
{
	static float	vector[] = {0.f, 0.f, 0.f, 1.f};
	static t_vec	vec = {vector, 4};
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
			vec.vector[0] = p->pos.x;
			vec.vector[1] = p->pos.y;
			vec.vector[2] = p->pos.z;
			res = ft_mat_multv(*transform, vec, NULL);
			p->pos.x = res->vector[0] / res->vector[3];
			p->pos.y = res->vector[1] / res->vector[3];
			p->pos.z = res->vector[2] / res->vector[3];
			++i.y;
		}
		++i.x;
	}
}
