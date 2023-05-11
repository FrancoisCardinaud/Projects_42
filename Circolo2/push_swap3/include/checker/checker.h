/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 17:24:14 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/11 17:48:22 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <../common/common.h>

int		execute_action(char *name, t_mem *mem);
void	read_instructions(t_mem *mem);

#endif
