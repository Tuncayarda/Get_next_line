/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuaydin <tuaydin@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:44:38 by tuaydin           #+#    #+#             */
/*   Updated: 2024/11/09 23:30:09 by tuaydin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnlb(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr_gnlb(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	else if (ft_strlen_gnlb(s) < start)
		return (ft_strdup_gnlb(""));
	if (len > ft_strlen_gnlb(s + start))
		len = ft_strlen_gnlb(s + start);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (i < len && start < ft_strlen_gnlb(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup_gnlb(char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(ft_strlen_gnlb(s1) + 1);
	if (str)
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strjoin_gnlb(char *s1, char *s2)
{
	char	*ptr;
	size_t	total_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen_gnlb(s1) + ft_strlen_gnlb(s2) + 1;
	ptr = malloc(total_len * sizeof(char));
	if (!ptr)
		return (free(s1), NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ptr[ft_strlen_gnlb(s1) + i] = s2[i];
		i++;
	}
	ptr[ft_strlen_gnlb(s1) + i] = '\0';
	return (free(s1), ptr);
}
