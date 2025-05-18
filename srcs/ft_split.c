#include "stack.h"

static size_t	count_tokens(const char *str, char separator)
{
	size_t	tokens;
	bool	inside_token;

	tokens = 0;
	inside_token = false;
	while (*str)
	{
		if (*str != separator && !inside_token)
		{
			inside_token = true;
			tokens++;
		}
		else if (*str == separator)
			inside_token = false;
		str++;
	}
	return (tokens);
}

static int	safe_malloc(char **strs, int position, size_t buffer)
{
	int	i;

	strs[position] = malloc(buffer);
	if (!strs[position])
	{
		i = 0;
		while (i < position)
			free(strs[i++]);
		free(strs);
		return (1);
	}
	return (0);
}

static int	fill(char **strs, const char *str, char separator)
{
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] == separator && str[i])
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] != separator && str[i])
			i++;
		if (safe_malloc(strs, j, i - start + 1))
			return (1);
		ft_strlcpy(strs[j], (char *)&str[start], i - start + 1);
		j++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	size_t	i;
	char	**words;

	if (!s || c == '\0')
		return (NULL);
	tokens = count_tokens(s, c);
	words = malloc((tokens + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	words[tokens] = NULL;
	if (fill(words, s, c) == 1)
	{
		i = 0;
		while (words[i])
			free(words[i++]);
		free(words);
		return (NULL);
	}
	return (words);
}
