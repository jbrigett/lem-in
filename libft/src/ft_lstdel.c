/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:08:15 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:08:16 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*nxtlst;

	if (alst)
	{
		lst = *alst;
		while (lst)
		{
			nxtlst = lst->next;
			del(lst->content, lst->content_size);
			free(lst);
			lst = nxtlst;
		}
		*alst = NULL;
	}
}
