/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:18 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:51:19 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void			reset(t_lem *lem, int r)
{
	int j;
	int i;

	j = 0;
	while (j < lem->number_of_rooms)
	{
		lem->matrix[j][r] = 0;
		if (j == r)
		{
			i = 0;
			while (i < lem->number_of_rooms)
				lem->matrix[j][i++] = 0;
		}
		j++;
	}
}

void			restore_path(t_lem *lem, t_path *path)
{
	int j;
	int i;

	j = 1;
	while (j < path->len)
	{
		i = 0;
		while (i < lem->number_of_rooms - 1)
		{
			if (!ft_strcmp(lem->rooms[i]->name, path->rooms[j]->name))
				reset(lem, i);
			i++;
		}
		j++;
	}
}

t_path			*get_path(t_lem *lem)
{
	int		cur;
	t_path	*path;
	int		k;
	int		i;

	cur = lem->number_of_rooms - 1;
	path = (t_path *)ft_memalloc(sizeof(t_path));
	path->len = lem->rooms[cur]->steps + 1;
	path->rooms = (t_room **)ft_memalloc(sizeof(t_room *) * path->len);
	k = path->len - 1;
	path->rooms[k--] = lem->rooms[lem->number_of_rooms - 1];
	while (lem->rooms[cur]->steps)
	{
		i = -1;
		while (++i < lem->number_of_rooms)
			if (lem->matrix[cur][i]
					&& lem->rooms[i]->steps == lem->rooms[cur]->steps - 1)
			{
				path->rooms[k--] = lem->rooms[i];
				cur = i;
			}
	}
	path->rooms[0] = lem->rooms[0];
	return (path);
}

t_lst_paths		*get_paths(t_lem *lem)
{
	t_lst_paths *paths;
	t_lst_paths *tmp;

	paths = 0;
	while (bfs(lem))
	{
		if (!paths)
		{
			paths = (t_lst_paths *)ft_memalloc(sizeof(t_lst_paths));
			paths->path = get_path(lem);
			paths->next = 0;
			restore_path(lem, paths->path);
			tmp = paths;
			continue;
		}
		tmp->next = (t_lst_paths *)ft_memalloc(sizeof(t_lst_paths));
		tmp->next->path = get_path(lem);
		tmp->next->next = 0;
		restore_path(lem, tmp->next->path);
		tmp = tmp->next;
	}
	return (paths);
}
