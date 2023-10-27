/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:46 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/27 15:51:27 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		g_stat;

void	handle_interrupt_signal(int signal_code)
{
	if (signal_code == SIGINT)
	{
		g_stat = 130;
		write(STDOUT_FILENO, "\n", 1); // Print a newline
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay(); // Redraw the prompt
	}
}
