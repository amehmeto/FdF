/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:10:20 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/04 06:10:09 by amehmeto         ###   ########.fr       */
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

# define SCALE 30

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

/*
typedef struct	s_size
{
	int		max_len;
	int		height;
}				t_size;
*/

int				my_key_funct(int keycode, void *param);
void			draw_line(t_line *l, t_env *e);
void			set_line(t_line *l, int x1, int y1, int x2, int y2);
//t_size			size_finder(const char *av);
void			print_raw_map(char ***map);
char			***map_parser(const char *av);
void			draw_wireframe(char ***map, t_env *e);

#endif
