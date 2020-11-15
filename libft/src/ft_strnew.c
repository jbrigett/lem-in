/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:19:09 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:19:11 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (0);
	if ((str = (char *)malloc(size + 1)))
	{
		ft_bzero(str, size + 1);
		return (str);
	}
	else
		return (NULL);
}
