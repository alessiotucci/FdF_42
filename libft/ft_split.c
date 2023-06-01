/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:10:04 by atucci            #+#    #+#             */
/*   Updated: 2023/02/01 11:01:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght_word(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	sublen;
	size_t	cs;

	sublen = 0;
	cs = 0;
	while (cs < ft_strlen(s))
	{
		while (cs < ft_strlen(s) && s[cs] == c)
			cs++;
		if (cs < ft_strlen(s))
		{
			start = cs;
			while (cs < ft_strlen(s) && s[cs] != c)
				cs++;
		end = cs;
		sublen = end - start;
			return (sublen);
		}
	}
	return (sublen);
}

size_t	ft_how_many_words(char const *s, char c)
{
	size_t	cs;
	size_t	ci;

	cs = 0;
	ci = 0;
	while (cs < ft_strlen(s))
	{
		while (cs < ft_strlen(s) && s[cs] == c)
		{
			cs++;
		}
		if (cs < ft_strlen(s))
		{
			ci++;
		}
		while (cs < ft_strlen(s) && s[cs] != c)
		{
			cs++;
		}
	}
	return (ci);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while ((src[i] != '\0') && (i < len))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	index;
	size_t	cs;
	size_t	start;

	res = malloc(sizeof(char *) * (ft_how_many_words(s, c) + 1));
	res[ft_how_many_words(s, c)] = 0;
	index = 0;
	cs = 0;
	while (cs < ft_strlen(s))
	{
		while (s[cs] == c && cs < ft_strlen(s))
			cs++;
		if (cs < ft_strlen(s))
		{
			start = cs;
			while (s[cs] != c && cs < ft_strlen(s))
				cs++;
			res[index] = malloc(sizeof(char) * (lenght_word(s + start, c) + 1));
			ft_strncpy(res[index], s + start, lenght_word(s + start, c));
			res[index][lenght_word(s + start, c)] = '\0';
			index++;
		}
	}
	return (res);
}
