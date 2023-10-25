/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:46:46 by fcardina          #+#    #+#             */
/*   Updated: 2023/10/25 17:58:14 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		g_stat;

void	handle_interrupt_signal(int signal_code)
{
	if (signal_code == SIGINT)
	{
		g_stat = 130;
		//ioctl(STDIN_FILENO, TIOCSTI, "\n");
		write(STDOUT_FILENO, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
