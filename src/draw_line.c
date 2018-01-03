/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:51:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/12/19 02:16:17 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vline(t_line *l, t_env *e)
{
	if (l->y1 > l->y2)
		ft_swap(&l->y1, &l->y2);
	while (l->y1 <= l->y2)
		mlx_pixel_put(e->mlx, e->win, l->x1, l->y1++, 0x00FF00FF);
}

static void		draw_hline(t_line *l, t_env *e)
{
	if (l->x1 > l->x2)
		ft_swap(&l->x1, &l->x2);
	while (l->x1 <= l->x2)
		mlx_pixel_put(e->mlx, e->win, l->x1++, l->y1, 0x00FF00FF);
}

static void		bresen_line(t_line *l, t_env *e)
{
	t_bvar		v;

	v.dx = ft_abs(l->x2 - l->x1);
	v.dy = ft_abs(l->y2 - l->y1);
	v.x_inc = (l->x1 < l->x2) ? 1 : -1;
	v.y_inc = (l->y1 < l->y2) ? 1 : -1;
	v.err = (v.dx > v.dy ? v.dx : -v.dy) / 2;
	while (l->x1 <= l->x2)
	{
		mlx_pixel_put(e->mlx, e->win, l->x1, l->y1, 0x00FFFFFF);
		v.eps = v.err;
		if (v.eps > -v.dx)
		{
			v.err -= v.dy;
			l->x1 += v.x_inc;
		}
		if (v.eps < v.dy)
		{
			v.err += v.dx;
			l->y1 += v.y_inc;
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
	{
		if (l->x1 > l->x2)
		{
			ft_swap(&l->x1, &l->x2);
			ft_swap(&l->y1, &l->y2);
			bresen_line(l, e);
		}
		else
			bresen_line(l, e);
	}
}
