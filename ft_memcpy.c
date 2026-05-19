/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 16:16:39 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/19 17:29:09 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*p;
	const unsigned char	*t;

	p = dest;
	t = src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		p[i] = t[i];
		i++;
	}
	return (dest);
}
