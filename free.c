/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:50:11 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:50:13 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	rmlst(t_lst *list)
{
	t_lst *tmp;

	while (list)
	{
		tmp = list;
		ft_strdel(&list->cont);
		list = list->next;
		free(tmp);
	}
}

void	rmrooms(t_room **rooms, int len)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (i < len)
	{
		tmp = rooms[i];
		free(rooms[i++]->name);
		free(tmp);
	}
	free(rooms);
}

void	rmmatrix(t_lem *lem)
{
	int j;

	j = 0;
	while (j < lem->number_of_rooms)
		free(lem->matrix[j++]);
	free(lem->matrix);
}

void	rmlem(t_lem *lem)
{
	if (lem->rooms)
		rmrooms(lem->rooms, lem->number_of_rooms);
	if (lem->matrix)
		rmmatrix(lem);
	free(lem);
}

void	rmpaths(t_lst_paths *paths)
{
	t_lst_paths	*tmp1;
	t_path		*tmp2;

	while (paths)
	{
		tmp1 = paths;
		free(paths->path->rooms);
		tmp2 = paths->path;
		paths = paths->next;
		free(tmp2);
		free(tmp1);
	}
}
