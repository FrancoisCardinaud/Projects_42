/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:33:50 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/23 17:52:13 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libft/libft.h"
# include "colors.h"
# include "get_next_line.h"
# include <dirent.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <sys/wait.h>
# include <unistd.h>

# define READ_END 0
# define WRITE_END 1

typedef struct s_prompt
{
	t_list	*cmds;
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

// Builtin functions
int			execute_builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int			check_builtin(t_mini *n);
int			mini_cd(t_prompt *prompt);
void		handle_cd_error(char **str[2]);
int			shell_pwd(void);
int			shell_echo(t_list *cmd);
int			shell_export(t_prompt *prompt);
int			shell_unset(t_prompt *prompt);
int			handle_exit(t_list *cmd, int *is_exit);

// Utils functions
char		**ft_cmdtrim(char const *s, char *set);
char		**ft_cmdsubsplit(char const *s, char *set);
char		*ft_strtrim_all(char const *s1, int squote, int dquote);
t_list		*populate_commands(char **args, int i);
int			get_fd(int oldfd, char *path, int flags[2]);
t_mini		*get_outfile1(t_mini *node, char **args, int *i);
t_mini		*get_outfile2(t_mini *node, char **args, int *i);
t_mini		*get_infile1(t_mini *node, char **args, int *i);
t_mini		*get_infile2(t_mini *node, char **args, int *i);
void		execute_custom_command(char ***output, char *full_path,
				char *arguments, char **environment);
void		get_cmd(t_prompt *prompt, t_list *cmd);
char		*expand_variables(char *str, int i, int quotes[2],
				t_prompt *prompt);
char		*expand_directory(char *str, int i, int quotes[2], char *var);
int			get_here_doc(char *str[2], char *aux[2]);
void		*shell_error(int err_type, char *param, int err);
char		*shell_retrieve_env(char *var, char **envp, int n);
char		**shell_setenv(char *var, char *value, char **envp, int n);
char		*shell_getprompt(t_prompt prompt);
void		release_content(void *content);
void		handle_interrupt_signal(int sig);
const char	*determine_color(char first_char);
void		handle_sigint_child(int sig);
void		*check_args(char *input, t_prompt *prompt_data);
// char	*mini_readline(t_prompt *prompt, char *str);
// void 	*mini_here_fd(int fd[2]);
void		*exec_cmd(t_prompt *prompt, t_list *cmd);
void		*check_to_fork(t_prompt *prompt, t_list *cmd, int fd[2]);
void		child_execute(t_prompt *prompt, t_mini *n, int l, t_list *cmd);
// int 	exec_builtin(t_prompt *prompt, int (*func)(t_prompt *));

#endif
