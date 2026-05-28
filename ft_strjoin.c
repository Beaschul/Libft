/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 18:24:56 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/27 17:04:10 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t 	s1_len;
	size_t 	s2_len;
	char 	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);

	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	res[s1_len + s2_len] = 0;
	if (!res)
		return (NULL);
	ft_strlcat(res, s1, s1_len + 1);
	ft_strlcat(res + s1_len, s2, s2_len + 1);
	return (res);
}