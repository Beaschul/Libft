/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschulz- <aschulz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 19:00:27 by aschulz-          #+#    #+#             */
/*   Updated: 2026/05/27 20:00:21 by aschulz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t splitlenght( char const *s, char c);
size_t fillsplit(char const *s, char c, char **split);

char **ft_split(char const *s, char c)
{
	size_t 	len;
	char 	**res;

	len = splitlenght(s, c);
	if (len == 0)
		return (NULL);
	res = ft_calloc(len + 1, sizeof(char *));
	fillsplit(s, c, res);
	return (res);
}

size_t wordlen(char const *s, char c)
{
	size_t i;
	
	i = 0;
	while (s[i] != '\0' &&  s[i] != c)
		i++;
	return (i);
}

size_t skipc(char const *s, char c)
{
	int i;

	while (s[i] && s[i] == c)
		i++;
	return (i);
}

size_t splitlenght( char const *s, char c)
{
	size_t lenght;
	size_t i;

	i = 0;
	lenght = 0;
	while (s[i])
	{
		i = skipc(s, c);
		if (!s[i])
			return (lenght);
		lenght++;
		i += wordlen(s, c);
	}
	return (lenght);
}

void fillsplit(char const *s, char c, char **split)
{
	size_t lenght;
	size_t i;
	size_t word_len;

	i = 0;
	lenght = 0;
	while (s[i])
	{
		i = skipc(s, c);
		if (!s[i])
			return;
		word_len = wordlen(s, c);
		split[lenght] = ft_substr(s, i, word_len);
		lenght++;
		i += word_len;
	}
	return;
}