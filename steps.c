/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:54 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 15:52:26 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	last_step(t_room *room, int *finished, t_room *end, int i)
{
	room->ant = 0;
	end->ant++;
	finished[i] = 1;
	print_step(i + 1, end->name);
}

void	first_step(t_path **ants, int *finished, int i, int j)
{
	if (j == ants[i]->len - 1 && finished[i] == 0)
	{
		if (ants[i]->rooms[1]->ant == 0)
		{
			ants[i]->rooms[0]->ant--;
			ants[i]->rooms[1]->ant = i + 1;
			print_step(i + 1, ants[i]->rooms[1]->name);
		}
	}
}

void	step(t_path **ants, int number_of_ants, int *finished, t_room *end)
{
	int i;
	int j;

	i = 0;
	while (i < number_of_ants)
	{
		j = 0;
		while (++j < ants[i]->len - 1)
			if (ants[i]->rooms[j]->ant == i + 1)
			{
				if (ants[i]->rooms[j + 1] != end)
				{
					if (ants[i]->rooms[j + 1]->ant == 0)
					{
						ants[i]->rooms[j]->ant = 0;
						ants[i]->rooms[j + 1]->ant = i + 1;
						print_step(i + 1, ants[i]->rooms[j + 1]->name);
						break ;
					}
				}
				else
					last_step(ants[i]->rooms[j], finished, end, i);
			}
		first_step(ants, finished, i++, j);
	}
}
