/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_in_mass.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amehmeto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 22:32:01 by amehmeto          #+#    #+#             */
/*   Updated: 2018/01/06 23:12:26 by amehmeto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./fdf.h"

void		free_in_mass(char **split)
{
	/*
	if (!*split)
		return ;
	free_in_mass(&(split[1]));
	free(*split);
	*/

	int	 i;

	i = 0;
	while (split[i])
		free(split[i++]);
}
