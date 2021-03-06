/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_redir_append.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 23:05:37 by anolivei          #+#    #+#             */
/*   Updated: 2021/09/12 23:07:15 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_pipe_redir_append(char *str)
{
	if (is_pipe_str(str))
		return (true);
	if (is_append(str))
		return (true);
	if (is_input_redir(str))
		return (true);
	if (is_output_redir(str))
		return (true);
	return (false);
}

bool	has_pipe_redir_append(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i] != NULL)
	{
		if (is_pipe_redir_append(tokens[1]))
			return (true);
		i++;
	}
	return (false);
}

int	count_pipe_redir_append(char **tokens)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tokens[i] != NULL)
	{
		if (is_pipe_redir_append(tokens[i]))
			count++;
		i++;
	}
	return (count);
}
