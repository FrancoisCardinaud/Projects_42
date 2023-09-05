/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toni <toni@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:49:07 by tblaase           #+#    #+#             */
/*   Updated: 2021/12/06 19:33:19 by toni             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_var_utils.h"
#include "inbuilt_utils.h"

/*
will reallocate env_var for one additional element
will append the new element
*/
static int	ft_export_new(t_env *envv, t_export *exp, char **argv)
{
	if (envv->env_var[exp->i] == NULL)
	{
		envv->env_var = ft_realloc_str_arr
			(envv->env_var, ft_str_arr_len(envv->env_var) + 1);
		envv->env_var[exp->i] = ft_strdup(argv[exp->j++]);
		ft_free_str(&exp->var);
		if (envv->env_var == NULL || envv->env_var[exp->i] == NULL)
			return (EXIT_FAILURE);
		if (export_special(envv, exp) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		return (2);
	}
	return (EXIT_SUCCESS);
}

/*
will change the value of the found element
*/
static int	ft_export_found(t_env *envv, t_export *exp, char **argv)
{
	int	check;

	if (ft_strcmp(envv->env_var[exp->i], exp->var) == 0
		|| ft_strcmp(envv->env_var[exp->i], exp->var) == 61)
	{
		ft_free_str(&envv->env_var[exp->i]);
		envv->env_var[exp->i] = ft_strdup(argv[exp->j++]);
		ft_free_str(&exp->var);
		if (envv->env_var[exp->i] == NULL)
			return (EXIT_FAILURE);
		exp->i++;
		return (2);
	}
	else
	{
		exp->i++;
		check = ft_export_new(envv, exp, argv);
		if (check == EXIT_FAILURE)
			return (EXIT_FAILURE);
		else if (check == 2)
			return (2);
	}
	return (EXIT_SUCCESS);
}

static void	ft_split_var(t_export *exp, char **argv)
{
	char	**var_split;

	var_split = ft_split(argv[exp->j], '=');
	if (var_split == NULL)
		exp->var = NULL;
	else
	{
		exp->var = ft_strdup(var_split[0]);
		ft_free_str_array(&var_split);
	}
}

/*
loops through all arguments and triggers either export_found or export_new
*/
static int	ft_export_loop(t_env *envv, t_export *exp, char **argv)
{
	int		check;

	exp->j = 1;
	while (argv[exp->j])
	{
		ft_split_var(exp, argv);
		if (exp->var == NULL)
			return (EXIT_FAILURE);
		exp->i = 0;
		if (export_wd(envv, exp, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		while (envv->env_var[exp->i])
		{
			check = ft_export_found(envv, exp, argv);
			if (check == 2)
				break ;
			else if (check == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

/*
mimics the behavior of the export function in bash
*/
int	export(char **argv)
{
	t_export	*exp;
	t_env		*envv;

	envv = get_envv();
	if (envv == NULL || envv->env_var == NULL)
		return (EXIT_FAILURE);
	if (argv[1] == NULL)
		export_only(envv);
	else if (export_input_error(argv) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	else
	{
		exp = ft_calloc(1, sizeof(t_export));
		if (exp == NULL)
			return (EXIT_FAILURE);
		if (reinit_env_var(envv, argv) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (ft_export_loop(envv, exp, argv) == EXIT_FAILURE)
		{
			ft_free((void *)&exp);
			return (EXIT_FAILURE);
		}
		ft_free((void *)&exp);
	}
	return (EXIT_SUCCESS);
}
