/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 17:05:40 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/25 10:02:17 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	t;
	int			i;

	t = s;
	i = 0;
	while (t[i] != '\0')
	{
		if (t[i] == c)
			return ((char *)&t[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&t[i]);
	return (NULL);
}
