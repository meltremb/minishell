/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntaxer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:56:35 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/06 14:51:15 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

void	init(void)
{
	t_data	*d;

	d = get_data();
	d->tokens = ft_calloc(1, sizeof(t_tokens));
}

int	make_list(char *line)
{
	char	**args;
	t_data	*d;
	int		k;

	d = get_data();
	k = -1;
	args = splitter(line);
	while (args[++k])
		dbl_lst_add_back(d->tokens, args[k]);
	ft_free_array((void ***) &args);
	return (1);
}