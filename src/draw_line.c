/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:51:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 06:23:25 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vline(t_line *l, t_env *e)
{
	int		tmp;

	if (l->y1 > l->y2)
	{
		tmp = l->y2;
		l->y2 = l->y1;
		l->y1 = tmp;
	}
	while (l->y1 <= l->y2)
		mlx_pixel_put(e->mlx, e->win, l->x1, l->y1++, 0x00FF00FF);
}

static void		draw_hline(t_line *l, t_env *e)
{
	int		tmp;

	if (l->x1 > l->x2)
	{
		tmp = l->x2;
		l->x2 = l->x1;
		l->x1 = tmp;
	}
	while (l->x1 <= l->x2)
		mlx_pixel_put(e->mlx, e->win, l->x1++, l->y1, 0x00FF00FF);
}

static void		bresen_line(t_line *l, t_env *e)
{
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;
	int		eps;
	int		err;

	dx = ft_abs(l->x2 - l->x1);
	dy = ft_abs(l->y2 - l->y1);
	x_inc = (l->x1 < l->x2) ? 1 : -1;
	y_inc = (l->y1 < l->y2) ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (l->x1 <= l->x2)
	{
		mlx_pixel_put(e->mlx, e->win, l->x1, l->y1, 0x00FFFFFF);
		eps = err;
		if (eps > -dx)
		{
			err -= dy;
			l->x1 += x_inc;
		}
		if (eps < dy)
		{
			err += dx;
			l->y1 += y_inc;
		}
	}
}

void			draw_line(t_line *l, t_env *e)
{
	if (l->x1 == l->x2 && l->y1 == l->y2)
		mlx_pixel_put(e->mlx, e->win, l->x1, l->y1, 0x00FFFFFF);
	else if (l->x1 == l->x2)
		draw_vline(l, e);
	else if (l->y1 == l->y2)
		draw_hline(l, e);
	else
			bresen_line(l, e);
}
