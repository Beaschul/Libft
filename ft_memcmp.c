/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 10:18:14 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/25 10:32:06 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*t1;
	const char	*t2;
	size_t		i;

	t1 = s1;
	t2 = s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
	}
	return (0);
}
