/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:38:10 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/20 02:02:50 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void		print_raw_map(char ***map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_putstr(map[i][j]);
			ft_putstr(" ");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
}

char		***map_parser(const char *av)
{
	char	***tab;
	char	*line;
	int		fd;
	int		i;

	tab = (char ***)malloc(sizeof(char **) * 50000);
	if ((fd = open(av, O_RDWR)) == -1)
		ft_putstr("open error\n");
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		tab[i++] = ft_strsplit(line, ' ');
		free(line);
	}
	tab[i] = NULL;
	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (tab);
}
