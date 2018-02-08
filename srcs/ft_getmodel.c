/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmodel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:50:24 by mmerabet          #+#    #+#             */
/*   Updated: 2018/02/08 21:42:32 by mmerabet         ###   ########.fr       */
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

static void	ft_getpoints(const char *line, t_model *model)
{
	t_list	*words;
	t_point	*points;
	t_point	point;
	char	*f;
	size_t	width;

	if (!line || !(words = ft_strsplit_lst(line, ' ')))
		return (NULL);
	width = ft_lstsize(words);
	if (!(points = (t_point *)malloc(sizeof(t_point) * width)))
		return (NULL);
	while (words)
	{
		if (words->content)
		{
			point.z = ft_atoi(words->content);
			if ((f = ft_strstr(words->content, ",0x")))
				point.color = ft_atoi_basec(f + 3, "0123456789abcdef");
			else
				points.color = 0xffffff;
		}
		words = words->next;
	}
	if (width < model->width)
	++model->height;
}

t_model			*ft_getmodel(const char *file_name)
{
	t_model	*model;
	t_list	*lines;
	int		fd;
	int		len;
	char	*line;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		return (NULL);
	if (!(model = (t_model *)ft_memalloc(sizeof(t_model))))
		return (NULL);
	while ((len = get_next_line(fd, &line)) >= 0)
	{

		ft_getpoints(line, model);
		++model->height;
		free(line);
	}
	return (model);
}
