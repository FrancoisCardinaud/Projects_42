/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:43:16 by fcardina          #+#    #+#             */
/*   Updated: 2023/08/26 01:46:12 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/get_next_line/get_next_line.h"
#include "../utils/libft/libft.h"
#include "../includes/sh.h"

void	new_line_prompt(t_csh *tcsh)
{
	(void)tcsh;
	ft_putstr(" ? ");
}

void	disp_prompt(t_csh *tcsh)
{
	(void)tcsh;
	ft_putstr("$> ");
}

static int	is_multiline(t_csh *tcsh, char *line)
{
	size_t	i;
	bool	backslash;

	i = 0;
	backslash = false;
	while (line[i] != '\0' && !is_comment(tcsh, line[i]))
	{
		backslash = false;
		if (line[i] == '\\')
		{
			backslash = true;
			if (line[i + 1] == '\\')
			{
				backslash = false;
				i++;
			}
		}
		i++;
	}
	if (line[i] != '\0')
		return (0);
	return (backslash);
}

static int	add_line(t_csh *tcsh, char **line)
{
	size_t	line_size;
	char	*tmp;
	char	*new_line;
	int		rtn;

	if (tcsh->var.is_a_tty)
		new_line_prompt(tcsh);
	rtn = get_next_line_pure(0, &tmp, &tcsh->prompt.buff);
	if (rtn == -1)
	{
		tcsh->var.return_value = 1;
		tcsh->var.exit = true;
		return (1);
	}
	line_size = ft_strlen(*line);
	new_line = ft_strnew(line_size + ft_strlen(tmp) + 1);
	if (new_line == NULL)
		return (1);
	ft_strcpy(new_line, *line);
	new_line[line_size] = '\n';
	ft_strcpy(&new_line[line_size + 1], tmp);
	ft_strdel(&tmp);
	ft_strdel(line);
	*line = new_line;
	return (0);
}

int	prompt_input(t_csh *tcsh, char **line)
{
	int rtn;

	if (tcsh->var.is_a_tty)
		disp_prompt(tcsh);
	rtn = get_next_line_pure(0, line, &tcsh->prompt.buff);
	if (rtn != 1)
	{
		if (rtn == -1)
			tcsh->var.return_value = 1;
		tcsh->var.exit = true;
		return (1);
	}
	while (is_multiline(tcsh, *line))
	{
		if (add_line(tcsh, line) != 0)
			return (1);
	}
	return (0);
}