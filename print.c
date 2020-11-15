/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 13:51:27 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/15 13:51:28 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	print_step(int id, char *name)
{
	ft_putchar('L');
	ft_putnbr(id);
	ft_putchar('-');
	ft_putstr(name);
	ft_putchar(' ');
}

void	print_room(char *name, int x, int y)
{
	ft_putstr(name);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void	print_link(char *name1, char *name2)
{
	ft_putstr(name1);
	ft_putchar('-');
	ft_putstr(name2);
	ft_putchar('\n');
}

void	print_info(t_lst *list)
{
	while (list)
	{
		if (!list->o)
		{
			ft_putstr(list->cont);
			ft_putchar('\n');
		}
		list = list->next;
	}
	ft_putchar('\n');
}

void	error(void)
{
	ft_putstr("ERROR\n");
}
