/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:56:35 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/05 10:58:37 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

static char *prompt(void)
{
	char    *line;

    line = readline("minishell>");
    while (line && line[0] == '\0')
        line = readline("minishell>");
    if (line)
        add_history(line);
    return (line);
}