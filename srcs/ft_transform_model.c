/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform_model.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 21:51:41 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/15 22:26:34 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
			if ((p = ft_getpoint(model, i.x, i.y)))
			{
				vec.vector[0] = p->pos.x;
				vec.vector[1] = p->pos.y;
				vec.vector[2] = p->pos.z;
				res = ft_mat_multv(*transform, vec, NULL);
				p->transpos.x = res->vector[0];
				p->transpos.y = res->vector[1];
				p->transpos.z = res->vector[2];
				ft_vec_del(&res);
			}
			++i.y;
		}
		++i.x;
	}
}
