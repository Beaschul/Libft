/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:40:15 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/25 15:12:55 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[0] == 0) //pq não if (little[i] = '\0')?
		return ((char *)big); //não precisa por & antes de big?
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0; //PQ?
	}
	return (0);
}
