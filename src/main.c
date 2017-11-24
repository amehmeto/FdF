/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 00:43:09 by amehmeto          #+#    #+#             */
/*   Updated: 2017/11/24 06:42:37 by amehmeto         ###   ########.fr       */
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
	t_line	l;
	t_env	e;

	if (ac == 5)
	{
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, 400, 400, "mlx 42");

		ft_putstr("WESH !!\n");
		l.x1 = atoi(av[1]);
		l.y1 = atoi(av[2]);
		l.x2 = atoi(av[3]);
		l.y2 = atoi(av[4]);

		draw_line(&l, &e);

		mlx_key_hook(e.win, (int (*)(void))my_key_funct, 0);
		mlx_loop(e.mlx);
	}
	else
		printf("4 arguments needed\n");
	return (0);
}
