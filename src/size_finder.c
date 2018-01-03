/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 21:32:36 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/03 21:34:53 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

t_size		size_finder(const char *av)
{
	char	*line;
	int		rslt;
	int		fd;
	t_size	s;

	if ((fd = open(av, O_RDWR)) == -1)
		ft_putstr("open error\n");
	s.height = 0;
	s.max_len = 0;
	while (get_next_line(fd, &line) == 1 && s.height++ >= 0)
	{
		rslt = (int)strlen(line);
		(s.max_len < rslt) ? s.max_len = rslt : s.max_len;
		printf("line # %d = \t %s\n", s.height, line);
		printf("\t \t max_len = %d \t height = %d\n", s.max_len, s.height);
	}
	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (s);
}
