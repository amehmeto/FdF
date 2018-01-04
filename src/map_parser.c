/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 23:38:10 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/04 01:52:29 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

char		***map_parser(const char *av, t_size s)
{
	char	***tab;
	char	*line;
	int		fd;
	int		j;
	int		i;

	//printf("Size = %d : %d \n", s.max_len, s.height);
	if ((fd = open(av, O_RDWR)) == -1)
		ft_putstr("open error\n");
	j = 0;
	while (get_next_line(fd, &line) == 1)
		tab[j++] = ft_strsplit(line, ' ');
	tab[j] = NULL;
/*  AFFICHER LE CONTENU DU DOUBLE TABLEAU 
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			ft_putstr(tab[j][i]);
			ft_putstr(" ");
			i++;
		}
		ft_putstr("\n");
		j++;
	}
*/
	if (close(fd) == -1)
		ft_putstr("close error\n");
	return (tab);
}
