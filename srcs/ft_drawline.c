/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 19:10:31 by mmerabet          #+#    #+#             */
/*   Updated: 2018/01/31 19:24:57 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"

void	ft_drawline(t_vec3 a, t_vec3 b, int color)
{
	t_vec3	d;
	t_vec3	s;
	int		e1;
	int		e2;

	d.x = ft_abs(b.x - a.x);
	d.y = ft_abs(b.y - a.y);
	s.x = (a.x < b.x ? 1 : -1);
	s.y = (a.y < b.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) = 2;
	while (1)
	{
		
	}
}
