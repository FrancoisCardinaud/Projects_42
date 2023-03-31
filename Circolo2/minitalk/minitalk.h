/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 23:07:12 by francoiscar       #+#    #+#             */
/*   Updated: 2023/03/31 16:24:17 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define G_BUFFSIZE 1024

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef TRUE
#  define TRUE 1
# endif

typedef struct s_stack
{
	char	message[G_BUFFSIZE];
	int		top_bit;
	int		top_byte;
	_Bool	all_receive;
	_Bool	buff_overflow;
}			t_stack;

t_stack		g_global = {{0}, 1 << 6, 0, FALSE, FALSE};

#endif
