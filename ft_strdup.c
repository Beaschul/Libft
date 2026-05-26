/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/26 16:28:58 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/26 16:41:01 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dest = (char *)malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, len);
	return (dest);
}
