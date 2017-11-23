/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 01:51:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/23 01:35:08 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_vline(int x, int y_1, int y_2, t_env *e)
{
	while (y_1 <= y_2)
		mlx_pixel_put(e->mlx, e->win, x, y_1, 0x00FF00FF);
}

static void		draw_hline(int x_1, int x_2, int y, t_env *e)
{
	while (x_1 <= x_2)
		mlx_pixel_put(e->mlx, e->win, x_1++, y, 0x00FF00FF);
}

void	draw_line(int x_1, int y_1, int x_2, int y_2, t_env *e)
{
	int		o;

	if (x_1 == x_2 && y_1 == y_2)
		mlx_pixel_put(e->mlx, e->win, x_1, y_1,	0x00FFFFFF);
	else if (x_1 == x_2)
		draw_vline(x_1, y_1, y_2, e);
	else if (y_1 == y_2)
		draw_hline(x_1, x_2, y_1, e);
	else
	{
	o = x_1;
	while (o <= x_2)
	{
		mlx_pixel_put(e->mlx, e->win, o, y_1 + ((y_2 - y_1) * (o - x_1))/(x_2 - x_1),
				0x00FFFFFF);
		o++;
	}
	}
}
