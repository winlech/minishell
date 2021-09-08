/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:55:50 by anolivei          #+#    #+#             */
/*   Updated: 2021/09/07 20:33:05 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_struct *mini)
{
	free_char_array(mini->tokens);
	free_line(mini->line_read);
	if (mini->path)
		free_char_array(mini->path);
	exit(0);
}

void	free_line(char *line_read)
{
	if (line_read)
	{
		free(line_read);
		line_read = (char *) NULL;
	}
}

void	free_char_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
