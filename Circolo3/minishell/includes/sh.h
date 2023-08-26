/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:45:49 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/26 02:07:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

/*
** Information about what type of redirection is given to a command
*/
typedef enum e_separator
{
	NONE = -1,
	SEMI_COLOMN = 0,
	PIPE,
	LEFT,
	D_LEFT,
	RIGHT,
	D_RIGHT,
	OR,
	AND
}					t_separator;

/*
** Information about the input or the output
** type -> is the token that seperate eack command
** file_name -> name of the file when "$> ls > file_name"
** fd -> fd of the previously mentioned file
*/
typedef struct s_direc
{
	int				fd;
	char			*file_name;
	t_separator		type;
}					t_direc;

/*
** Linked list created during the pars.
** Each list contain one command line and
** each element contain one command to execute
** cmd -> the argv part of the execve
** rtn -> return value of the fork
** pid -> pid used by the fork (if no fork than -1)
** left, right -> respectively the input and output
** next -> next element
*/
typedef struct s_cmd
{
	char			**cmd;
	int				rtn;
	int				pid;
	bool			is_bg;
	t_direc			left;
	t_direc			right;
	struct s_cmd	*next;
}					t_cmd;

/*
** Token is a list of "word" for exemple 'ls;ls' is 'ls' ';' 'ls'
** but "this is a test" one token
** Quoted is usefull because because of the diffrence between '$HOME'/"$HOME"
** and ~/Download "~/Download"
** Quoted can be ", ' or \
*/
typedef struct s_oken
{
	char			*str;
	char			quoted;
	bool			linked;
	size_t			base;
	struct s_oken	*next;
}					t_oken;

/*
** Environement structure. Contains many usefull variables for the shell.
** env -> Copy of the main's env. Can be updated by the user at will and
** will be used as reference for exec.
** oldpwd -> Previous working directory, used for cd -
*/
typedef struct s_env
{
	char			**env;
	char			*oldpwd;
}					t_env;

/*
** Everything needed by the prompt
** Will by used lot more for the 21sh
** line -> the full command line in one string
** buff -> the "rest" of the read's buffer
*/
typedef struct s_prompt
{
	char			*buff;
}					t_prompt;

/*
** Variable that may be needed at any moment
*/
typedef struct s_var
{
	bool			exit;
	bool			is_a_tty;
	uint8_t			return_value;
}					t_var;

/*
** Main struct used from the begining until the end
** prompt-> prompt, is a litle bit like print f with variables
** return_value -> exit's value or last process value.
** Will be returned upon ctrl-d or exit built-in call.
** exit -> Core loop stop condition.
** tty -> Determines if the prompt and exit message must be displayed.
** env, input, alias, hist -> various struct for various part
*/
typedef struct s_csh
{
	t_prompt		prompt;
	t_var			var;
	t_env			env;
}					t_csh;

/*
** global
*/
extern const char *const g_separators[];

/*
** tcsh main fonctions
*/
int					init_tcsh(t_csh *tcsh, const char *env[]);
int					loop_tcsh(t_csh *tcsh);
void				free_tcsh(t_csh *tcsh);

/*
** Prompt
*/
int					prompt_input(t_csh *tcsh, char **line);
void				disp_prompt(t_csh *tcsh);
void				new_line_prompt(t_csh *tcsh);

/*
** Tokenisation

int					tokenise_line(t_csh *tcsh, t_oken **tokens, char **line);
int					expand_token(t_csh *tcsh, t_oken **new, t_oken *tokens);
char				*expand_env_var(t_csh *tcsh, t_oken *str);
t_cmd				*create_cmd(t_cmd **cmd);
int					token_to_cmd(t_csh *tcsh, t_cmd **cmd, t_oken *tokens);
void				print_cmd(t_cmd *cmd);
t_oken				*create_token(t_oken **tokens);
t_oken				*get_last_token(t_oken **tokens);
void				print_token(t_oken *token);
void				del_token(t_oken *tokens);
void				del_cmd(t_cmd *cmd);*/

/*
** Exec
*/
int					exec_cmd(t_csh *tcsh, t_cmd *cmd);
int					fork_cmd(t_csh *tcsh, t_cmd *cmd, char *ex_path);
bool				is_relative_path(char *cmd);
int					find_and_fork_cmd(t_csh *tcsh, t_cmd *cmd);
int					cmd_err(t_cmd *cmd, char *err);
int					command_not_found(t_cmd *cmd);
int					permission_denied(t_cmd *cmd);

/*
** Env
*/
int					get_env_var_nb(char **env, char *var);
char				*get_env_var(char **env, char *var);

/*
** Signal
*/
void				disable_signal(t_csh *tcsh);
void				enable_signal(t_csh *tcsh);

/*
** is.c
*/
int					is_separator(char c);
int					is_space(char c);
int					is_comment(t_csh *tcsh, char c);
bool				is_linked(t_csh *tcsh, char *line);

/*
** line
*/
int					add_word_token(t_csh *tcsh, t_oken **tokens, char *line,
						size_t *i);
int					add_separator_token(t_csh *tcsh, t_oken **tokens,
						char *line, size_t *i);
int					add_squote_token(t_csh *tcsh, t_oken **tokens, char *line,
						size_t *i);
int					add_dquote_token(t_csh *tcsh, t_oken **tokens, char *line,
						size_t *i);
int					add_backslash_token(t_csh *tcsh, t_oken **tokens,
						char *line, size_t *i);

/*
** builtin
*/
bool				is_builtin(char *cmd);
int					exec_builtin(t_csh *tcsh, t_cmd *cmd);
int					builtin_echo(t_csh *tcsh, t_cmd *cmd);
int					builtin_cd(t_csh *tcsh, t_cmd *cmd);
int					builtin_setenv(t_csh *tcsh, t_cmd *cmd);
int					builtin_unsetenv(t_csh *tcsh, t_cmd *cmd);
int					builtin_env(t_csh *tcsh, t_cmd *cmd);
int					builtin_exit(t_csh *tcsh, t_cmd *cmd);

#endif
