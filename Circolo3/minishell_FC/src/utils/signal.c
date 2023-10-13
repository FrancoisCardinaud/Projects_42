/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*   Created: 2021/11/18 15:44:53 by aperez-b          #+#    #+#             */
/*   Updated: 2022/03/08 12:38:07 by aperez-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	g_stat;

void	handle_interrupt_signal(int signal_code)
{
	if (signal_code == SIGINT)
	{
		g_stat = 130;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}
