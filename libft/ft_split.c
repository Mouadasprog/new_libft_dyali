/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouad <mouad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:54:08 by mouad             #+#    #+#             */
/*   Updated: 2024/11/10 10:00:49 by mouad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*allocate_word(const char *start, size_t len)
{
	char	*word;
	size_t	i;

	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**words;
	int		i;

	i = 0;
	words = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !words)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			words[i] = allocate_word(s, c);
			if (!words[i++])
				return (NULL);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	words[i] = NULL;
	return (words);
}
int main(void)
{
	char	test[] = "ben mahmoud mouad";
	char delimiter = ' ';
	char	**words = ft_split(test,delimiter);
	int i = 0;
	while(words[i])
	{
		printf("%s\n",words[i]);
		i++;
	}
}
