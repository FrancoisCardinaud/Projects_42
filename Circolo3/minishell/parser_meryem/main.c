/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:51 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/13 16:06:47 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

int main(int ac, char **av, char **envp)
{
	t_prompt prompt;

	prompt.envp = envp;
	if(ac != 2)
	{
		handle_error(INVALID_ARG_ERRORS, 1, NULL);
		exit(EXIT_FAILURE);
	}
	set_env(prompt);
	while(ac){

	}
}
