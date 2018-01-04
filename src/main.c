/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/04 03:52:14 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"
#define SCALE 100

int		my_key_funct(int keycode, void *param)
{
	(void)param;
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	draw_wireframe(char ***map, t_env *e)
{
	t_line	l;
	int		i;
	int		j;

	print_raw_map(map);
	i = 0;
	while (map[i] && map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			printf("i = %d \t j = %d \t map[i][j] = %s\n", i, j, map[i][j]);
			l.x1 = i * SCALE;
			l.y1 = j * SCALE;
			l.x2 = (i + 1) * SCALE;
			l.y2 = (j ) * SCALE;
			draw_line(&l, e);
			l.x1 = i * SCALE;
			l.y1 = j * SCALE;
			l.x2 = i * SCALE;
			l.y2 = (j + 1) * SCALE;
			draw_line(&l, e);
			j++;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	char	***map;
	t_env	e;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf source_file.fdf\n");
		return (0);
	}
	else
	{
		map = map_parser(av[1]);

		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1000, 1000, "FdF maggle");

		draw_wireframe(map, e.mlx);

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	return (0);
}
