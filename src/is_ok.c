/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ok.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 05:20:48 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/07 03:17:25 by amehmeto         ###   ########.fr       */
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

static int			check_line_size(char *line, int size)
{
	char	**splitted_line;
	int		i;

	if (!(splitted_line = ft_strsplit(line, ' ')))
		return (9);
	if (counter(splitted_line) != size)
	{
		free(splitted_line);
		return (3);
	}
	i = 0;
	while (splitted_line[i])
		free(splitted_line[i++]);
	free(splitted_line);
	return (0);
}

int					is_ok(const char *av)
{
	char	**splitted_line;
	char	*line;
	int		fd;
	int		size;
	int		i;

	if ((fd = open(av, O_RDWR)) == -1)
	{
		ft_putstr("open error\n");
		return (1);
	}
	if (get_next_line(fd, &line) == 1)
	{
		if (!(splitted_line = ft_strsplit(line, ' ')))
			return (9);
		free(line);
		size = counter(splitted_line);
		i = 0;
		while (splitted_line[i])
			free(splitted_line[i++]);
		free(splitted_line);
	}
	else
		return (2);
	while (get_next_line(fd, &line) == 1)
	{
		if (check_line_size(line, size))
		{
			free(line);
			return (3);
		}
		free(line);
	}
	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (0);
}
