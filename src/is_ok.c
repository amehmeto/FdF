/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 05:20:48 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/05 06:17:45 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

static int			counter(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

/*
static int			is_data_ok(char **s_line)
{
	int		i;

	i = 0;
	while (s_line[i])
		if (s_line[i] !=
	return (NULL);
}
*/

int					is_ok(const char *av)
{
	char	**splitted_line;
	char	*line;
	int		fd;
	int		size;

	if ((fd = open(av, O_RDWR)) == -1)
	{
		ft_putstr("open error\n");
		return (1);
	}
	if (get_next_line(fd, &line) == 1)
	{
		splitted_line = ft_strsplit(line, ' ');
		size = counter(splitted_line);
	}
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		if (counter(splitted_line = ft_strsplit(line, ' ')) != size)
			return (3);
		//if (is_data_ok(splitted_line))
		//	return (4);
	}
	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (0);
}
