/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:10:20 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/06 20:19:29 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../../Libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define SCALE 20
# define Z_SCALE 10
# define X_MARGIN 300
# define Y_MARGIN 20

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

typedef struct	s_bvar
{
	int		dx;
	int		dy;
	int		x_inc;
	int		y_inc;
	int		eps;
	int		err;
}				t_bvar;

typedef struct	s_coor
{
	int		x;
	int		y;
	char	***map;
}				t_coor;

void			draw_line(t_line *l, t_env *e);
void			margin_adjustment(t_line *l, t_coor c, int var);
void			z_adjustment(t_line *l, t_coor c, int var);
void			iso_adjustment(t_line *l);
void			print_raw_map(char ***map);
int				is_ok(const char *av);
char			***map_parser(const char *av);

#endif
