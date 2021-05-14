/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 16:59:08 by fporto            #+#    #+#             */
/*   Updated: 2021/05/12 16:59:13 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	rng(char *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s[i] || start > ft_strlen(s))
		return (0);
	while (s[start + i] && i < len)
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	range;

	if (!s)
		return (NULL);
	j = 0;
	range = rng((char *)s, start, len);
	str = malloc(range + 1);
	if (ft_strlen(s) >= start)
	{
		if (!str)
			return (NULL);
		i = start;
		while (s[i] && j < range)
		{
			str[j] = s[i];
			i++;
			j++;
		}
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str1;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	str1 = malloc(i + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str1[i] = s1[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
