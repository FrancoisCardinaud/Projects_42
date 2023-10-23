/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:47:10 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/24 01:01:21 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*locate_command(char **env_path, char *cmd)
{
	char	*full_path;
	char	*temp;
	int		i;

	full_path = NULL;
	i = -1;
	while (env_path && env_path[++i])
	{
		free(full_path);
		temp = ft_strjoin(env_path[i], "/");
		if (!temp)
			return (NULL);
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (NULL);
		if (access(full_path, F_OK) == 0)
			break ;
	}
	if (!env_path || !env_path[i])
	{
		free(full_path);
		return (NULL);
	}
	return (full_path);
}

static DIR	*validate_command(t_prompt *prompt, t_list *cmd, char ***p_split)
{
	t_mini	*n;
	DIR		*dir;
	char	*path;

	n = cmd->content;
	dir = NULL;
	if (n && n->full_cmd)
		dir = opendir(*n->full_cmd);
	if (n && n->full_cmd && ft_strchr(*n->full_cmd, '/') && !dir)
	{
		*p_split = ft_split(*n->full_cmd, '/');
		n->full_path = ft_strdup(*n->full_cmd);
		free(n->full_cmd[0]);
		n->full_cmd[0] = ft_strdup((*p_split)[ft_matrixlen(*p_split) - 1]);
	}
	else if (!check_builtin(n) && n && n->full_cmd && !dir)
	{
		path = shell_retrieve_env("PATH", prompt->envp, 4);
		*p_split = ft_split(path, ':');
		free(path);
		n->full_path = locate_command(*p_split, *n->full_cmd);
		if (!n->full_path || !n->full_cmd[0] || !n->full_cmd[0][0])
			shell_error(NCMD, *n->full_cmd, 127);
	}
	return (dir);
}

void	get_cmd(t_prompt *prompt, t_list *cmd)
{
	t_mini	*n;
	DIR		*dir;
	char	**p_split;

	n = cmd->content;
	p_split = NULL;
	dir = validate_command(prompt, cmd, &p_split);
	if (!check_builtin(n) && n && n->full_cmd && dir)
		shell_error(IS_DIR, *n->full_cmd, 126);
	else if (!check_builtin(n) && n && n->full_path && access(n->full_path,
			F_OK) == -1)
		shell_error(NDIR, n->full_path, 127);
	else if (!check_builtin(n) && n && n->full_path && access(n->full_path,
			X_OK) == -1)
		shell_error(NPERM, n->full_path, 126);
	if (dir)
		closedir(dir);
	ft_free_matrix(&p_split);
}

void	*exec_cmd(t_prompt *prompt, t_list *cmd)
{
	int	fd[2];

	get_cmd(prompt, cmd);
	if (pipe(fd) == -1)
		return (shell_error(PIPERR, NULL, 1));
	if (!check_to_fork(prompt, cmd, fd))
		return (NULL);
	close(fd[WRITE_END]);
	if (cmd->next && !((t_mini *)cmd->next->content)->infile)
		((t_mini *)cmd->next->content)->infile = fd[READ_END];
	else
		close(fd[READ_END]);
	if (((t_mini *)cmd->content)->infile > 2)
		close(((t_mini *)cmd->content)->infile);
	if (((t_mini *)cmd->content)->outfile > 2)
		close(((t_mini *)cmd->content)->outfile);
	return (NULL);
}
