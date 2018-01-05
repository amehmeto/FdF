/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/05 11:10:13 by amehmeto         ###   ########.fr       */
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

static void		draw_tile(t_line *l, t_env *e)
{
	iso_adjustment(l);
	draw_line(l, e);
}

void	draw_wireframe(char ***map, t_env *e)
{
	t_line	l;
	t_coor	c;

	print_raw_map(map);
	c.y = 0;
	while (map[c.y] && map[c.y + 1])
	{
		c.x = 0;
		while (map[c.y][c.x])
		{
			if (map[c.y][c.x + 1])
			{
				margin_adjustment(&l, c, 1);
				z_adjustment(&l, c, map, 1);
				draw_tile(&l, e);
			}
			if (map[c.y + 1][c.x])
			{
				margin_adjustment(&l, c, 2);
				z_adjustment(&l, c, map, 2);
				draw_tile(&l, e);
			}
			c.x++;
		}
		if (map[c.y + 1][c.x])
		{
			margin_adjustment(&l, c, 2);
			z_adjustment(&l, c, map, 2);
			draw_tile(&l, e);
		}
		c.y++;
	}
	c.x = 0;
	while (map[c.y][c.x])
	{
		if (map[c.y][c.x + 1])
		{
			margin_adjustment(&l, c, 1);
			z_adjustment(&l, c, map, 1);
			draw_tile(&l, e);
		}
		c.x++;
	}
}

int		main(int ac, char **av)
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
		ft_putnbr(a);
		return (0);
	}
	else
	{
		map = map_parser(av[1]);

		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 1100, 1100, "FdF maggle");

		draw_wireframe(map, e.mlx);

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	return (0);
}
