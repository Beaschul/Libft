/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:00:27 by aschulz-          #+#    #+#             */
/*   Updated: 2026/06/01 10:53:37 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_char(char const *s, char c);
static size_t	word_len(char const *s, char c);
static size_t	split_len(char const *s, char c);
static void		fill_split(char const *s, char c, char **split);

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	len;

	if (!s)
		return (NULL);
	len = split_len(s, c);
	res = ft_calloc(len + 1, sizeof(char *));
	if (!res)
		return (NULL);
	if (len > 0)
		fill_split(s, c, res);
	return (res);
}

static size_t	skip_char(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (i);
}

static size_t	word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	split_len(char const *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		i += skip_char(s + i, c);
		if (!s[i])
			return (len);
		len++;
		i += word_len(s + i, c);
	}
	return (len);
}

static void	fill_split(char const *s, char c, char **split)
{
	size_t	i;
	size_t	index;
	size_t	w_len;

	i = 0;
	index = 0;
	while (s[i])
	{
		i += skip_char(s + i, c);
		if (!s[i])
			return ;
		w_len = word_len(s + i, c);
		split[index] = ft_substr(s, i, w_len);
		if (!split[index])
			return ;
		index++;
		i += w_len;
	}
}
