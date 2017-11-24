/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 03:10:20 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 03:21:19 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_env
{
	void	*mlx;
	void	*win;
}				t_env;

int		my_key_funct(int keycode, void *param);
void	draw_line(int x_1, int y_1, int x_2, int y_2, t_env *e);

#endif
