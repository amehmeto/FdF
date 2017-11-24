/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:10:20 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 06:34:44 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../Libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

typedef struct	s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}				t_line;


int				my_key_funct(int keycode, void *param);
void			draw_line(t_line *l, t_env *e);

#endif
