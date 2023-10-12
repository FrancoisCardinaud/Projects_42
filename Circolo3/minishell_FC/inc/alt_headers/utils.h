#ifndef UTILS_H
# define UTILS_H

char	**ft_cmdtrim(char const *s, char *set);
char	**ft_cmdsubsplit(char const *s, char *set);
char	*ft_strtrim_all(char const *s1, int squote, int dquote);
t_list	*fill_nodes(char **args, int i);
int		get_fd(int oldfd, char *path, int flags[2]);
t_mini	*get_outfile1(t_mini *node, char **args, int *i);
t_mini	*get_outfile2(t_mini *node, char **args, int *i);
t_mini	*get_infile1(t_mini *node, char **args, int *i);
t_mini	*get_infile2(t_mini *node, char **args, int *i);
void	exec_custom(char ***out, char *full, char *args, char **envp);
void	get_cmd(t_prompt *prompt, t_list *start, char **split_path, char *path);
char	*expand_vars(char *str, int i, int quotes[2], t_prompt *prompt);
char	*expand_path(char *str, int i, int quotes[2], char *var);
int		get_here_doc(char *str[2], char *aux[2]);
void	*mini_perror(int err_type, char *param, int err);
char	*mini_getenv(char	*var, char **envp, int n);
char	**mini_setenv(char *var, char *value, char **envp, int n);
char	*mini_getprompt(t_prompt prompt);
void	free_content(void *content);

#endif
