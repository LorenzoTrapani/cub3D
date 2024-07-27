/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lotrapan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 19:18:45 by lotrapan          #+#    #+#             */
/*   Updated: 2024/03/19 17:23:35 by lotrapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char separator)
{
	size_t	count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char const *str, char separator, size_t *cursor)
{
	char		*next_str;
	size_t		len;
	size_t		start;
	size_t		i;

	while (str[*cursor] == separator)
		(*cursor)++;
	start = *cursor;
	while ((str[*cursor] != separator) && str[*cursor] != '\0')
		(*cursor)++;
	len = *cursor - start;
	next_str = malloc(len + 1);
	if (NULL == next_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		next_str[i] = str[start + i];
		i++;
	}
	next_str[len] = '\0';
	return (next_str);
}

static void	free_all(char **result, size_t i)
{
	i--;
	while (i > 0)
	{
		i--;
		free(result[i]);
	}
	free(result);
}

static char	**split_alloc(char **result, char const *str,
		char separator, size_t word_count)
{
	size_t	cursor;
	size_t	i;

	i = 1;
	cursor = 0;
	while (i <= word_count)
	{
		result[i] = get_next_word(str, separator, &cursor);
		if (result[i] == NULL)
		{
			free_all(result, i);
			return (NULL);
		}
		i++;
	}
	result[word_count + 1] = NULL;
	return (result);
}

char	**ft_split_argv(char const *str, char separator)
{
	size_t	words_count;
	char	**result;

	if (!str)
		return (NULL);
	words_count = count_words(str, separator);
	if (!words_count)
		exit(1);
	result = malloc(sizeof(char *) * (words_count + 2));
	if (!result)
		return (NULL);
	result[0] = malloc(1);
	if (!result[0])
	{
		free(result);
		return (NULL);
	}
	result[0][0] = '\0';
	result = split_alloc(result, str, separator, words_count);
	return (result);
}

/* int main() {
    char const *str = "442 3435 656 76 3 6546 324";
    char separator = ' ';
    char **split = ft_split_argv(str, separator);

    if (split != NULL) {
        for (size_t i = 0; split[i] != NULL; i++) {
            printf("split[%zu]: '%s'\n", i, split[i]);
        }
    }
	return 0;
} */