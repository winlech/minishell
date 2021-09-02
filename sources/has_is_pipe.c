#include "minishell.h"

bool is_pipe(char c)
{
	if (c == '|')
		return true;
	return false;
}

bool is_pipe_str(char *str)
{
	if (str == NULL)
		return (false);
	if (ft_strlen(str) == 1 && ft_strncmp(str, "|", 1))
		return true;
	return false;
}

bool has_pipe(char **tokens)
{
	int i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (is_pipe_str(tokens[i]))
			return true;
	}
	return false;
}
