/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:50:02 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:50:03 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		find_this_room(char *name, t_lem *lem)
{
	int i;

	i = 0;
	while (i < lem->number_of_rooms)
	{
		if (ft_strcmp(lem->rooms[i]->name, name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int		check_rooms(char *a, char *b, t_lem *lem)
{
	if (!find_this_room(a, lem) || !find_this_room(b, lem))
	{
		ft_strdel(&a);
		ft_strdel(&b);
		rmlem(lem);
		return (0);
	}
	return (1);
}
