/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:17:51 by meltremb          #+#    #+#             */
/*   Updated: 2023/06/06 14:36:23 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define READLINE_LIBRARY

# include"reworked-libft/libft.h"
# include"dbl_lists/dbl_lists.h"
# include"readline/readline.h"
# include"readline/history.h"
# include<signal.h>
# include<sys/stat.h>
# include<dirent.h>
# include<sys/ioctl.h>
# include<termios.h>
# include<curses.h>
# include<term.h>

typedef struct s_data
{
	t_tokens	*tokens;
}				t_data;

t_data	*get_data(void);
void	init(void);
int		char_checker(char c);
char	**splitter(char *line);
int		make_list(char *line);

#endif
