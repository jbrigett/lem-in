/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roomparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:43 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:51:44 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		get_name_len(char *s)
{
	char	*end;

	end = s;
	while (*end != ' ')
		end++;
	return (end - s);
}

void	parseroom(t_room *room, char *info)
{
	int	len;
	int	i;

	len = get_name_len(info);
	room->name = (char *)ft_memalloc(sizeof(char) * len + 1);
	i = 0;
	while (i < len)
	{
		room->name[i] = info[i];
		i++;
	}
	room->name[i++] = 0;
	while (ft_isdigit(info[i]))
		room->coord_x = room->coord_x * 10 + info[i++] - '0';
	i++;
	while (ft_isdigit(info[i]))
		room->coord_y = room->coord_y * 10 + info[i++] - '0';
}

t_room	*get_start(t_lst *list)
{
	while (list)
	{
		if (list->s && list->r)
			return (newroom(list->cont));
		list = list->next;
	}
	return (0);
}

t_room	*get_end(t_lst *list)
{
	while (list)
	{
		if (list->e && list->r)
			return (newroom(list->cont));
		list = list->next;
	}
	return (0);
}

t_room	**get_rooms(t_lst *list, int len)
{
	t_room	**rooms;
	int		i;
	t_lst	*p;

	i = 0;
	rooms = newarr(len);
	rooms[i++] = get_start(list);
	p = list;
	while (p)
	{
		if (p->r && !p->s && !p->e)
			rooms[i++] = newroom(p->cont);
		p = p->next;
	}
	rooms[i] = get_end(list);
	return (rooms);
}
