/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/04 06:17:16 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

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
	int		x;
	int		y;

	print_raw_map(map);
	y = 0;
	while (map[y] && map[y + 1])
	{
		x = 0;
		while (map[y][x])
		{
			set_line(&l, x, y, x + 1, y);
			draw_line(&l, e);
			set_line(&l, x, y, x, y + 1);
			draw_line(&l, e);
			x++;
		}
		set_line(&l, x, y, x, y + 1);
		draw_line(&l, e);
		y++;
	}
	x = 0;
	while (map[y][x])
	{
		set_line(&l, x, y, x + 1, y);
		draw_line(&l, e);
		x++;
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
		e.win = mlx_new_window(e.mlx, 500, 500, "FdF maggle");

		draw_wireframe(map, e.mlx);

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	return (0);
}
