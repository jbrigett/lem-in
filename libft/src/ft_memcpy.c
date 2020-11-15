/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:11:40 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:11:42 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst && src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
	}
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dst);
}
