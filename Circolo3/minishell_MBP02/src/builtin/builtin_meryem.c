/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_meryem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:37:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/09/19 17:02:33 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
int	build_cd(t_prompt *info);                 // Done
int	build_exit(t_list *cmd, int *check_exit); // Done
int	build_export(t_prompt *info);
int	build_unset(t_prompt *info);
int	build_echo(t_mini *node);                                            // Done
int	builtin_command(t_prompt *prompt, t_list *cmd, int *is_exit, int n); // done
int	is_builtin(t_mini *n);                                               // Done
*/

int	build_echo(t_mini *node)
{
	int		i;
	bool	flag;
	char	**args;

	flag = false;
	args = node->full_cmd;
	i = 0;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		flag = true;
		args++;
	}
	// loop through the arguments and print them
	while (args[i])
	{
		printf("%s", args[i]);
		if (args[i + 1])
			printf(" ");
		i++;
	}
	// print a new line unless the -n falg was provided
	if (!flag)
		printf("\n");
	return (0);
}

int	builtin_command(t_prompt *prompt, t_list *cmd, int *is_exit, int n)
{
	int	status;

	char **parsed_cmd; //(the parsed command tokens)
	n = 0;
	while (cmd)
	{
		parsed_cmd = ((t_mini *)cmd->content)->full_cmd;
		if (parsed_cmd)
			n = ft_strlen(*parsed_cmd);
		if (parsed_cmd && !ft_strncmp(*parsed_cmd, "exit", n) && n == 4)
			status = build_exit(cmd, is_exit);
		else if (!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "cd", n)
				&& n == 2)
			status = build_cd(prompt);
		else if ((!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "export",
						n) && n == 2))
			status = build_export(prompt);
		else if ((!cmd->next && parsed_cmd && !ft_strncmp(*parsed_cmd, "unset",
						n) && n == 2))
			status = build_unset(prompt);
		else
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
			execute_cmd();
			// responsible for executing a command in a shell pipeline
		}
		cmd = cmd->next;
	}
	return (status);
}
int	is_builtin(t_mini *n)
{
	int	len_cmd;

	if (!n->full_cmd)
		return (0);
	if (n->full_cmd && ft_strchr(n->full_cmd, '/') || n->full_path
		&& ft_strchr(n->full_path, '/'))
		;
	return (0);
	len_cmd = ft_strlen(n->full_cmd);
	if (!ft_strncmp(n->full_cmd, "pwd", len_cmd) && len_cmd == 3)
		return (1);
	if (!ft_strncmp(n->full_cmd, "cd", len_cmd) && len_cmd == 2)
		return (1);
	if (!ft_strncmp(n->full_cmd, "export", len_cmd) && len_cmd == 6)
		return (1);
	if (!ft_strncmp(n->full_cmd, "unset", len_cmd) && len_cmd == 5)
		return (1);
	if (!ft_strncmp(n->full_cmd, "echo", len_cmd) && len_cmd == 4)
		return (1);
	if (!ft_strncmp(n->full_cmd, "exit", len_cmd) && len_cmd == 4)
		return (1);
	return (0);
}

int	build_cd(t_prompt *info)
{
	char	*args;
	char	*current_path;
	char	*new_path;

	args = ((t_mini *)info->cmds->content)->full_cmd[1];
	// get the second argument
	if (args == NULL)
	{
		args = get_env("HOME", info->envp, 4);
		if (args == NULL)
		{
			printf("cd: HOME not set\n");
			return (1);
		}
	}
	current_path = getcwd(NULL, 0);
	if (!current_path)
	{
		perror("cd");
		return (1);
	}
	if (chdir(args) == -1)
	{
		if (args[0] == '\0')
			return (1);
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(args, 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (1);
	}
	info->envp = set_or_update("OLDPWD", current_path, info->envp, 6);
	new_path = getcwd(NULL, 0);
	if (!new_path)
	{
		perror("cd");
		return (1);
	}
	info->envp = set_or_update("PWD", new_path, info->envp, 3);
	free(new_path);
	return (0);
}

int	pwd(void)
{
	char	*buffer;

	buffer = getcwd(NULL, 0);
	// used to store the path of the current working directory,
	// NULL allocate memory,
	// 0 specifie the size of the buffer used to store the path
	ft_putendl_fd(buffer, 1);
	// used to print the content of the content of buffer to the standard
	// output(file descriptor 1)
	free(buffer);
	return (0);
}

int	build_exit(t_list *cmd, int *check_exit)
{
	t_mini	*node;
	long	exit_status[2];

	node = cmd->content;
	*check_exit = !cmd->next; // check iif the next command is an exit
	if (*check_exit)
		ft_putstr_fd("exit\n", 2);
	// if it's true this means then cmd is an exit cmd so the program print
	// exit to the standard eror stream (file descriptor)
	if (!node->full_cmd || !node->full_cmd[1])
		return (0);
	exit_status[1] = ft_atoi(node->full_cmd[1]);
	if (!exit_status[1])
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(node->full_cmd[1], 2);
		ft_putstr_fd("exit: numeric argument required\n", 2);
		retrun(255);
	}
	else if (node->full_cmd[1])
	{
		check_exit = 0;
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	exit_status[0] %= 256 + 256 * (exit_status[0] < 0);
	return (exit_status);
}

int	build_export(t_prompt *prompt)
{
	char	**argv;
	int		pos;
	int		i;

	i = 1;
	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	while (argv[i] != NULL)
	{
		// it pass the current environment variable
		pos = var_in_envp(argv[i], prompt->envp, i);
		// variable is already exist
		if (pos >= 0)
		{
			free(prompt->envp[pos]);
			prompt->envp[pos] = ft_strdup(argv[1]);
		}
		// var not found
		else if (pos == -1)
			prompt->envp = ft_extend_matrix(prompt->envp, argv[i]);
		// extends the prompt->envp array by adding the new variable
		i++;
	}
	return (0);
}
// i should take take the variable an the enviremnt array
// iterate throught the environment array and find the variale you want to remove
// once you found the variable,
// remove it from the environment array(shifting the subsequence elements up)

int	build_unset(t_prompt *prompt)
{
	char **argv;
	char *variable;
	int i;

	i = 1;
	argv = ((t_mini *)prompt->cmds->content)->full_cmd;
	// check if there are at least two arguments
	if (ft_strlen(argv) < 2)
		retrun(0);
	while (argv[i] != NULL)
	{
		if (argv[i][ft_strlen(argv[i]) - 1] != '=')
		{
			variable = ft_strjoin(argv[i], "=");
			free(argv[i]);
			argv[i] = variable;
		}
		i++;
		remove_unset(prompt->envp, argv[i]);
	}
	return (0);
}