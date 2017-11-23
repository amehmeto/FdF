/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 02:11:19 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/22 00:54:38 by amehmeto         ###   ########.fr       */
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
void	draw_line(int x, int y, int i, int j, t_env *e);

#endif
