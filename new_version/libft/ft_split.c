/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporciel <fporciel@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 09:05:07 by fporciel          #+#    #+#             */
/*   Updated: 2023/06/01 13:18:30 by fporciel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* 
* This software is made available to anyone who wants to retrace the 
* author's learning path through the projects of school 42.
* Copyright (C) 2023  fporciel
* 
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <https://www.gnu.org/licenses/>.
*
* You can contact the author at: 
*- fporciel@student.42roma.it
*/

#include "./libft.h"

static char	**split_free_null(char ***phrase, size_t count)
{
	size_t	other_count;

	other_count = 0;
	while (other_count < count)
	{
		if (((*phrase)[other_count]) != NULL)
		{
			free(((*phrase)[other_count]));
			((*phrase)[other_count]) = NULL;
		}
		other_count++;
	}
	if (((*phrase)[count]) != NULL)
	{
		free(((*phrase)[count]));
		((*phrase)[count]) = NULL;
	}
	free(*phrase);
	(*phrase) = NULL;
	return (*phrase);
}

static size_t	splitlen(const char *str, char delim, int param, size_t *start)
{
	size_t	words;
	ssize_t	letters;

	words = 0;
	letters = 0;
	if (param == 0)
	{
		while (str[letters] != 0)
		{
			while (str[letters] == delim)
				letters++;
			if ((str[letters] != delim) && (str[letters] != 0))
				words++;
			while ((str[letters] != delim) && (str[letters] != 0))
				letters++;
		}
		return (words);
	}
	while (str[(*start)] == delim)
		(*start)++;
	while ((str[(*start)]) && (str[(*start)] != delim) && (letters++ >= 0))
		(*start)++;
	return (letters);
}

static char	*split_word(char *word, const char *str, char delim, size_t *start)
{
	size_t	letters;
	size_t	start_word;
	size_t	count;

	letters = splitlen(str, delim, 1, start);
	word = (char *)malloc(sizeof(char) * (letters + 1));
	if (word == NULL)
		return (NULL);
	start_word = ((*start) - letters);
	count = 0;
	while (count < letters)
	{
		word[count] = str[start_word + count];
		count++;
	}
	word[count] = 0;
	return (word);
}

char	**ft_split(const char *str, char delim)
{
	size_t	count;
	size_t	count_words;
	size_t	start;
	char	**phrase;

	count = 0;
	start = 0;
	if ((str == NULL) || ((*str) == 0))
		return (NULL);
	count_words = splitlen(str, delim, 0, &start);
	phrase = (char **)malloc(sizeof(char *) * (count_words + 1));
	if (phrase == NULL)
		return (NULL);
	while (count < count_words)
	{
		phrase[count] = split_word(phrase[count], str, delim, &start);
		if (phrase[count] == NULL)
			return (split_free_null(&phrase, count));
		count++;
	}
	phrase[count] = NULL;
	return (phrase);
}
