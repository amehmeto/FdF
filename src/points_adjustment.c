/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_adjustment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 07:12:38 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/05 03:26:24 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void	set_line(t_line *l, int x1, int y1, int x2, int y2)
{
	l->x1 = x1 * SCALE + X_MARGIN;
	l->y1 = y1 * SCALE + Y_MARGIN;
	l->x2 = x2 * SCALE + X_MARGIN;
	l->y2 = y2 * SCALE + Y_MARGIN;	
}

void	z_adjustment(t_line *l, int z1, int z2)
{
	l->y1 -= (z1 * Z_SCALE);
	l->y2 -= (z2 * Z_SCALE); 
}

void	iso_adjustment(t_line *l)
{
	t_line	l_cpy;

	l_cpy = *l;
	l->x1 = (l_cpy.x1 - l_cpy.y1) ;
	l->y1 = (l_cpy.x1 + l_cpy.y1) ;
	l->x2 = (l_cpy.x2 - l_cpy.y2) ;
	l->y2 = (l_cpy.x2 + l_cpy.y2) ;	
}
