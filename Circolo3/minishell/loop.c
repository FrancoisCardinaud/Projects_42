/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:52:31 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/26 02:07:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "utils/libft/libft.h"
#include "includes/sh.h"

int	loop_tcsh(t_csh *tcsh)
{
	char *line;
	t_oken *tokens;
	t_oken *exp_tokens;
	t_cmd *cmd;
	int cnt;

	line = NULL;
	cnt = prompt_input(tcsh, &line);
	tokens = NULL;
	if (cnt == 0)
		cnt = tokenise_line(tcsh, &tokens, &line);
	ft_strdel(&line);
	exp_tokens = NULL;
	if (cnt == 0)
		cnt = expand_token(tcsh, &exp_tokens, tokens);
	del_token(tokens);
	cmd = NULL;
	if (cnt == 0)
		cnt = token_to_cmd(tcsh, &cmd, exp_tokens);
	del_token(exp_tokens);
	if (cnt == 0)
		cnt = exec_cmd(tcsh, cmd);
	del_cmd(cmd);
	return (cnt);
}