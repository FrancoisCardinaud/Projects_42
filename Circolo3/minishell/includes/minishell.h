/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:32:40 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/16 01:08:14 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//# include "error_utils.h"
# include "libft.h"
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define EXIT_SYNTAX_ERROR 258
# define EXIT_CMD_NOT_FOUND 127
# define EXIT_CTRL_D 130

typedef struct s_prompt
{
	char	*cmd;
	char	**envp;
	int		pid;
}			t_prompt;

typedef enum e_handle_error
{
	COMMAND_NOT_FOUND,
	SYNTAX_ERRORS,
	REDIRECTION_ERRORS,
	PERMISSION_ERRORS,
	MEMORY_ALL_ERRORS,
	ENV_VAR_ERRORS,
	FILE_NOT_FOUND,
	BUILT_IN_COMMAND_ERRORS,
	INPUT_ERRORS,
	PIPE_RED_ERRORS,
	INVALID_ARG_ERRORS
}			t_handle_error;

/*int			echo(char **args);
int			export(char **argv);
int			unset(char **argv);
int			env(char **argv);
int			pwd(void);
int			cd(char **argv);
int			exit_inbuilt(char *args[]);

void		handle_cmd_signals(void);
void		handle_global_signals(void);*/

#endif
