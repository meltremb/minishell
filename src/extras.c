/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:15:18 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/06 14:54:34 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/minishell.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

int	char_checker(char c)
{
	if (c != ' ' && c != 9 && c != '|' && c != '&'
			&& c != '\n' && c != ';' && c != '('
				&& c != ')' && c != '<' && c!= '>' && c != '\0')
		return (1);
	return (0);
}

size_t	ft_len(const char *s)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (char_checker(*s) != 0)
		{
			ret++;
			while (*s && char_checker(*s) != 0)
				s++;
		}
		else
			s++;
	}
	return (ret);
}

char	**splitter(char *line)
{
	char	**returned;
	int		len;
	int		i;

	if (!line)
		return (0);
	i = 0;
	returned = malloc(sizeof(char *) * (ft_len(line) + 1));
	while (*line)
	{
		if (char_checker(*line) != 0)
		{
			len = 0;
			while (*line && char_checker(*line) != 0 && ++len)
				line++;
			returned[i++] = ft_substr(line - len, 0, len);
		}
		else
			line++;
	}
	returned[i] = NULL;
	return (returned);
}