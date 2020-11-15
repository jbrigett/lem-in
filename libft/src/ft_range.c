/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:14:25 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:14:26 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *ofints;

	i = 0;
	if (max <= min)
		return (NULL);
	if (!(ofints = (int *)malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (i < (max - min))
	{
		ofints[i] = i + min;
		i++;
	}
	return (ofints);
}
