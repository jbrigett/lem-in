/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbrigett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 14:07:35 by jbrigett          #+#    #+#             */
/*   Updated: 2020/11/14 14:07:37 by jbrigett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(int c)
{
	unsigned char ch;

	ch = (unsigned char)c;
	if ((ch >= '\t' && ch <= '\r') || ch == ' ')
		return (1);
	return (0);
}