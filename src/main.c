/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/20 02:20:29 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int		key_funct(int keycode, void *param)
{
	(void)param;
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}

static void		draw_tile(t_line *l, t_env *e, t_coor c, int var)
{
	margin_adjustment(l, c, var);
	z_adjustment(l, c, var);
	iso_adjustment(l);
	draw_line(l, e);
}

static void		free_will(char ***map)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			free(map[y][x]);
			x++;
		}
		free(map[y]);
		y++;
	}
	free(map);
}

static void		draw_wireframe(char ***map, t_env *e)
{
	t_line	l;
	t_coor	c;

	print_raw_map(map);
	c.map = map;
	c.y = 0;
	while (map[c.y] && map[c.y + 1])
	{
		c.x = -1;
		while (map[c.y][++c.x])
		{
			if (map[c.y][c.x + 1])
				draw_tile(&l, e, c, 1);
			if (map[c.y + 1][c.x])
				draw_tile(&l, e, c, 2);
		}
		if (map[c.y + 1][c.x])
			draw_tile(&l, e, c, 2);
		(c.y)++;
	}
	c.x = -1;
	while (map[c.y][++c.x] && map[c.y][c.x + 1])
		draw_tile(&l, e, c, 1);
	free_will(map);
}

int				main(int ac, char **av)
{
	char	***map;
	int		a;
	t_env	e;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf source_file.fdf\n");
		return (0);
	}
	else if ((a = is_ok(av[1])))
	{
		ft_putstr("Error with the file\n");
		return (0);
	}
	else
	{
		map = map_parser(av[1]);
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1100, 1100, "FdF maggle");
		draw_wireframe(map, e.mlx);
		mlx_key_hook(e.win, (int (*)(void))key_funct, 0);
		mlx_loop(e.mlx);
	}
	return (0);
}
