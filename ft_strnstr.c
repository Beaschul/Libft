/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:40:15 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/25 11:21:46 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		J = 0; //PQ?
	}
	return (0);
}
