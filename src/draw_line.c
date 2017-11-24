/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:51:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 03:45:11 by amehmeto         ###   ########.fr       */
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
	int		eps;
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;

	eps = 0;
	dx = (x_2 - x_1);
	dy = (y_2 - y_1);
	x_inc = (dx > 0) ? 1 : -1;
	y_inc = (dy > 0) ? 1 : -1;
	while (x_1 <= x_2)
	{
		mlx_pixel_put(e->mlx, e->win, x_1 += x_inc, y_1, 0x00FFFFFF);
		eps += dy;
		if ((eps << 1) >= dx)
		{
			eps -= dx;
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
		bresen_line(x_1, y_1, x_2, y_2, e);
}
