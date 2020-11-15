/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:35 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:51:36 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room	**newqueue(int size)
{
	t_room	**queue;

	queue = (t_room **)ft_memalloc(sizeof(t_room *) * size);
	return (queue);
}

int		qin(t_room **queue, int size, t_room *room)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (!queue[i])
		{
			queue[i] = room;
			return (1);
		}
		i++;
	}
	return (0);
}

void	qrm(t_room **queue, int size)
{
	int i;

	i = 1;
	while (i < size)
	{
		queue[i - 1] = queue[i];
		i++;
	}
	queue[size - 1] = 0;
}

void	qfree(t_room **queue, int size)
{
	int i;

	i = 0;
	while (i < size)
		free(queue[i++]);
	free(queue);
}
