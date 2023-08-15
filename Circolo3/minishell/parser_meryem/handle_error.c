/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mennaji <mennaji@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:23:35 by mennaji           #+#    #+#             */
/*   Updated: 2023/08/13 15:50:06 by mennaji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell1.h"

//Command Not Found
//syntax errrors
//Redirection Errors
//Permission Errors
//Memory Allocation Errors
//Environment Variable Errors
//Exit Status Errors
//File Not Found Errors
//Built-in Command Errors:
//Input Errors
//Pipe and Redirection Errors
//Invalid Argument Errors

void command_not_found(const char *cmd)
{
	printf(stderr, "minishell: command not found: %s\n", cmd);
	 exit(EXIT_FAILURE);
}

void syntax_error()
{
	printf(stderr, "minishell: syntax error\n");
	exit(EXIT_FAILURE);
}

void permission_error(const char *file)
{
	printf(stderr, "minishell: permission denied: %s\n", file);
	exit(EXIT_FAILURE);
}

void memory_error()
{
	printf(stderr, "minishell: memory allocation error\n");
	exit(EXIT_FAILURE);
}

void handle_error(t_handle_error type_error, const char *cmd)
{

	if(type_error == COMMAND_NOT_FOUND)
		command_not_found(cmd);
	if(type_error == SYNTAX_ERRORS)
		syntax_errors();
	if(type_error == REDIRECTION_ERRORS)
		redirection_errors();
	if(type_error == PERMISSION_ERRORS)
		perm_errors();
	if(type_error == MEMORY_ALL_ERRORS)
		memory_error();
	if(type_error == ENV_VAR_ERRORS)
		env_var_error();
	if(type_error == FILE_NOT_FOUND)
		file_not_found();
	if(type_error == BUILT_IN_COMMAND_ERRORS)
		built_in_command();
	if(type_error == INPUT_ERRORS)
		input_error();
	if(type_error == PIPE_RED_ERRORS)
		pipe_errors();
	if(type_error == INVALID_ARG_ERRORS)
		invalid_arg();
}
