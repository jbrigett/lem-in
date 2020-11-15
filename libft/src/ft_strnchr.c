/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:18:20 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:18:22 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s1, int c, int len)
{
	if (!len || !s1)
		return (0);
	while (*s1 != (char)c && len--)
		if (!*s1++)
			return (NULL);
	if (*s1 != (char)c)
		return (0);
	return ((char *)s1);
}
