#ifndef BUILTIN_H
# define BUILTIN_H

int		builtin(t_prompt *prompt, t_list *cmd, int *is_exit, int n);
int		is_builtin(t_mini *n);
int		mini_cd(t_prompt *prompt);
void	cd_error(char **str[2]);
int		mini_pwd(void);
int		mini_echo(t_list *cmd);
int		mini_export(t_prompt *prompt);
int		mini_unset(t_prompt *prompt);
int		mini_exit(t_list *cmd, int *is_exit);

#endif
