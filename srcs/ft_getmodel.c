/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmodel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:50:24 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/13 15:21:37 by mmerabet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "get_next_line.h"
#include "ft_list.h"
#include "ft_printf.h"
#include "ft_mem.h"
#include "ft_types.h"
#include "ft_str.h"
#include <fcntl.h>
#include <stdlib.h>

static void	getheights(const t_list *words, t_point *points, size_t y)
{
	char	*f;
	size_t	i;

	i = 0;
	while (words)
	{
		if (words->content)
		{
			points[i].pos.x = (float)i;
			points[i].pos.y = (float)y;
			points[i].pos.z = ft_atod(words->content);
			if ((f = ft_strstr(words->content, ",0x")))
				points[i].color = ft_atoi_basec(f + 3, "0123456789abcdef");
			else
				points[i].color = 0xffffff;
				points[i].color = rand() % 0xffffff;// (int)points[i].pos.z;
			++i;
		}
		words = words->next;
	}
}

static t_point	*getpoints(const char *line, t_model *model)
{
	t_list	*words;
	t_point	*points;
	size_t	width;

	if (!line || !(words = ft_strsplit_lst(line, ' ')))
		return (NULL);
	width = ft_lstsize(words);
	if (!model->points)
		model->width = width;
	if (model->width != width)
	{
		ft_printf_fd(2, "Found wrond line length. Exiting.\n");
		exit(-1);
	}
	if (!(points = (t_point *)malloc(sizeof(t_point) * width)))
	{
		ft_printf_fd(2, "Failed to generate points chain. Exiting.\n");
		exit(-1);
	}
	getheights(words, points, model->height);
	return (points);
}

t_model			*ft_getmodel(const char *file_name)
{
	t_model	*model;
	int		fd;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if (!(model = (t_model *)ft_memalloc(sizeof(t_model))))
		return (NULL);
	while (get_next_line(fd, &line) >= 0)
	{
		model->points = ft_memjoin_clr2(model->points,
				sizeof(t_point) * (model->width * model->height),
				getpoints(line, model), sizeof(t_point) * model->width);
		++model->height;
		free(line);
	}
	return (model);
}

t_point			*ft_getpoint(t_model *model, size_t x, size_t y)
{
	t_point	*p;

	if (!model || !model->points)
		return (NULL);
	p = (model->points + (x + model->width * y));
	return (p);
}

void			ft_printmodel(t_model *model)
{
	size_t	x;
	size_t	y;
	t_point	*pa;
	t_point	*pb;

	y = 0;
	while (y < model->height)
	{
		x = 0;
		while (x < model->width)
		{
			pa = ft_getpoint(model, x, y);
			if (x + 1 < model->width && (pb = ft_getpoint(model, x + 1, y)))
				ft_drawline(ft_getpoint(model, x, y)->transpos,
						pb->transpos, pa->color);
			if (y + 1 < model->height && (pb = ft_getpoint(model, x, y + 1)))
			{
				ft_drawline(ft_getpoint(model, x, y)->transpos,
						pb->transpos, pa->color);
			}
			++x;
		}
		++y;
	}
}
