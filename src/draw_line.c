/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:51:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 05:14:54 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vline(int x, int y_1, int y_2, t_env *e)
{
	int		tmp;

	if (y_1 > y_2)
	{
		tmp = y_2;
		y_2 = y_1;
		y_1 = tmp;
	}
	while (y_1 <= y_2)
		mlx_pixel_put(e->mlx, e->win, x, y_1++, 0x00FF00FF);
}

static void		draw_hline(int x_1, int x_2, int y, t_env *e)
{
	int		tmp;

	if (x_1 > x_2)
	{
		tmp = x_2;
		x_2 = x_1;
		x_1 = tmp;
	}
	while (x_1 <= x_2)
		mlx_pixel_put(e->mlx, e->win, x_1++, y, 0x00FF00FF);
}

static void		bresen_line(int x_1, int y_1, int x_2, int y_2, t_env *e)
{
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;
	int		eps;
	int		err;

	dx = ft_abs(x_2 - x_1);
	dy = ft_abs(y_2 - y_1);
	x_inc = (x_1 < x_2) ? 1 : -1;
	y_inc = (y_1 < y_2) ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (x_1 <= x_2)
	{
		mlx_pixel_put(e->mlx, e->win, x_1, y_1, 0x00FFFFFF);
		eps = err;
		if (eps > -dx)
		{
			err -= dy;
			x_1 += x_inc;
		}
		if (eps < dy)
		{
			err += dx;
			y_1 += y_inc;
		}
	}
}

void			draw_line(int x_1, int y_1, int x_2, int y_2, t_env *e)
{
	if (x_1 == x_2 && y_1 == y_2)
		mlx_pixel_put(e->mlx, e->win, x_1, y_1, 0x00FFFFFF);
	else if (x_1 == x_2)
		draw_vline(x_1, y_1, y_2, e);
	else if (y_1 == y_2)
		draw_hline(x_1, x_2, y_1, e);
	else
	{
		if (x_1 > x_2)
			bresen_line(x_2, y_2, x_1, y_1, e);
		else
			bresen_line(x_1, y_1, x_2, y_2, e);
	}
}
