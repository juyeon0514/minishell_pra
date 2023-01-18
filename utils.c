/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juykang <juykang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 16:27:27 by juykang           #+#    #+#             */
/*   Updated: 2023/01/18 13:45:18 by juykang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_white_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && !(str[i] >= 9 && str[i] <= 13))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (*needle == '\0')
	{
		return ((char *)haystack);
	}
	while (*(haystack + i) && i < len)
	{
		temp = 0;
		while (needle[temp] && (needle[temp] == haystack[i + temp])
			&& (i + temp) < len)
		{
			temp++;
		}
		if (needle[temp] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	const size_t	size = ft_strlen(s) + 1;

	i = 0;
	while (i < size)
	{
		if (s[i] == (char) c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	return (0);
}
