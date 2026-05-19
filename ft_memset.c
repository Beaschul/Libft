/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 12:19:28 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/19 17:12:54 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n > 0)
	{
		*p = c;
		p++;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	char src[] = "seila";
	char dest[10];

	ft_memset(dest, 'a', 2);
	ft_strlcpy(dest, src, 0); ????
	printf("%s\n, src")
}
*/