/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:50:57 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:50:58 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	markup(t_lst *list)
{
	while (list)
	{
		if (is_room(list->cont))
			list->r = 1;
		else if (is_link(list->cont))
			list->l = 1;
		else if (list->cont[0] == '#' && list->cont[1] != '#')
			list->c = 1;
		else if (!ft_strcmp("##start", list->cont))
		{
			list->s = 1;
			if (list->next && is_room(list->next->cont))
				list->next->s = 1;
		}
		else if (!ft_strcmp("##end", list->cont))
		{
			list->e = 1;
			if (list->next && is_room(list->next->cont))
				list->next->e = 1;
		}
		else if (list->cont[0] == '#' && list->cont[1] == '#')
			list->o = 1;
		list = list->next;
	}
}
