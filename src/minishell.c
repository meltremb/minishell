/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:21:07 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/05 12:51:29 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*call_prompt(void)
{
	char	*line;

	line = readline("");
	while (line && line[0] == '\0')
		line = readline("");
	if (line)
		add_history(line);
	return (line);
}

int	main(void)
{
	call_prompt();
}
