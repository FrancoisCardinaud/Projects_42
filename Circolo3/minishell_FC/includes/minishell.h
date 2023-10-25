/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:33:50 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/25 17:57:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include "colors.h"
# include "get_next_line.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_prompt
{
	t_list	*cmd;
	char	**envp;
	pid_t	pid;
}			t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int		infile;
	int		outfile;
}			t_mini;

enum		e_mini_error
{
	QUOTE = 1,
	NDIR = 2,
	NPERM = 3,
	NCMD = 6,
	DUPERR = 7,
	FORKERR = 8,
	PIPERR = 9,
	PIPENDERR = 10,
	MEM = 11,
	IS_DIR = 12,
	NOT_DIR = 13
};

// Builtins
int			execute_builtin(t_prompt *data, t_list *cmd, int *exit_flag, int l);
int			check_builtin(t_mini *cmd_data);
int			shell_cd(t_prompt *data);
int			shell_pwd(void);
int			shell_echo(t_list *cmd);

// Env
int			shell_export(t_prompt *data);
int			shell_unset(t_prompt *data);

// Error handling
int			handle_exit(t_list *cmd, int *is_exit);
void		handle_cd_error(char **arguments[2]);
void		*shell_error(int error_type, char *parameter, int error_code);
void		release_content(void *content);

// Lexer
t_list		*populate_commands(char **args, int c);

// Expander
char		*expand_variables(char *input, int index, int quote_flags[2],
				t_prompt *data);
char		*expand_dir(char *input, int index, int quote[2], char *var);

// Executor
void		*check_to_fork(t_prompt *data, t_list *cmd_list, int pipe_fd[2]);
void		execute_child(t_prompt *data, t_list *cmd_list, int pipe_fd[2]);

// Env
char		*shell_retrieve_env(char *key, char **envp, int key_len);
char		**shell_setenv(char *key, char *value, char **envp, int key_len);

// Prompt
char		*shell_getprompt(t_prompt prompt_data);
const char	*determine_color(char first_char);

// Parser
void		*check_args(char *output, t_prompt *p);

// Utils functions
char		**ft_cmdtrim(char const *str, char *delimiters);
char		**ft_cmdsubsplit(char const *str, char *delimiters);
char		*ft_strtrim_all(char const *str, int quote, int quotes);
t_mini		*get_outfile1(t_mini *node, char **args, int *index);
t_mini		*get_outfile2(t_mini *node, char **args, int *index);
t_mini		*get_infile1(t_mini *node, char **args, int *index);
t_mini		*get_infile2(t_mini *node, char **args, int *index);
void		execute_custom_command(char ***output, char *full_path,
				char *arguments, char **environment);
void		get_cmd(t_prompt *data, t_list *cmd);
int			get_here_doc(char *input_str[2], char *auxiliary[2]);
void		handle_interrupt_signal(int signal_code);
void		*exec_cmd(t_prompt *prompt, t_list *cmd);

// Unused functions
// int			get_fd(int oldfd, char *path, int flags[2]);
// void		handle_sigint_child(int sig);
// char	*mini_readline(t_prompt *prompt, char *str);
// void 	*mini_here_fd(int fd[2]);
// int 	exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));

#endif
