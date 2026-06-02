/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:16:09 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 11:14:52 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	getstart(char const *s1, char const *set);
size_t	getend(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	char	*res;

	start = getstart(s1, set);
	if (start >= ft_strlen(s1))
		return (ft_strdup(""));
	len = getend(s1, set) - start + 1;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	return (ft_substr(s1, start, len));
}

size_t	getstart(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]))
			i++;
		else
			return (i);
	}
	return (i);
}

size_t	getend(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, s1[i]))
			i--;
		else
			return (i);
	}
	return (i);
}
