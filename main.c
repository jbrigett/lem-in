/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:50:46 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:50:48 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int	main(void)
{
	t_lem		*lem;
	t_lst_paths	*paths;

	if (!(lem = parse()))
		return (1);
	if (bfs(lem))
		print_info(lem->list);
	else
	{
		error();
		rmlst(lem->list);
		rmlem(lem);
		return (1);
	}
	rmlst(lem->list);
	paths = get_paths(lem);
	lem->rooms[0]->ant = lem->number_of_ants;
	run_ants(lem->number_of_ants, paths);
	rmpaths(paths);
	rmlem(lem);
	return (0);
}
