/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_adjustment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 07:12:38 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/06 20:20:30 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	margin_adjustment(t_line *l, t_coor c, int var)
{
	l->x1 = c.x * SCALE + X_MARGIN;
	l->y1 = c.y * SCALE + Y_MARGIN;
	l->x2 = c.x * SCALE + X_MARGIN;
	l->y2 = c.y * SCALE + Y_MARGIN;
	if (var == 1)
		l->x2 = (c.x + 1) * SCALE + X_MARGIN;
	if (var == 2)
		l->y2 = (c.y + 1) * SCALE + Y_MARGIN;
}

void	z_adjustment(t_line *l, t_coor c, int var)
{
	l->y1 -= ft_atoi(c.map[c.y][c.x]) * Z_SCALE;
	if (var == 1)
		l->y2 -= ft_atoi(c.map[c.y][c.x + 1]) * Z_SCALE;
	if (var == 2)
		l->y2 -= ft_atoi(c.map[c.y + 1][c.x]) * Z_SCALE;
}

void	iso_adjustment(t_line *l)
{
	t_line	l_cpy;

	l_cpy = *l;
	l->x1 = (l_cpy.x1 - l_cpy.y1);
	l->y1 = (l_cpy.x1 + l_cpy.y1);
	l->x2 = (l_cpy.x2 - l_cpy.y2);
	l->y2 = (l_cpy.x2 + l_cpy.y2);
}
