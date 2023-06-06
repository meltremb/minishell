/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:21:07 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/06 14:53:48 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char	*prompt(void)
{
	char	*line;

	line = readline("minishell>");
	while (line && line[0] == '\0')
		line = readline("minishell>");
	if (line)
		add_history(line);
	return (line);
}

int	main(void)
{
	char	*line;

	line = prompt();
	init();
	make_list(line);
	return (0);
}
