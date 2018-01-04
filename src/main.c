/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/04 00:38:51 by amehmeto         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
	{
		ft_putstr("usage: ./fdf source_file.fdf\n");
		return (0);
	}
	else
	{
		map_parser(av[1], size_finder(av[1]));

		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 400, 400, "mlx 42");

		printf("main.c OK\n");

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	return (0);
}
