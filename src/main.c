/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 03:48:16 by amehmeto         ###   ########.fr       */
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
	int		x_1, y_1, x_2, y_2;
	t_env	e;

	if (ac == 5)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 400, 400, "mlx 42");

		x_1 = atoi(av[1]);
		y_1 = atoi(av[2]);
		x_2 = atoi(av[3]);
		y_2 = atoi(av[4]);

		draw_line(x_1, y_1, x_2, y_2, &e);

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	else
		printf("4 arguments needed\n");
	return (0);
}
