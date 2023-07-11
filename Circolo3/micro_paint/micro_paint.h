/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:29:32 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/16 18:29:38 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_paint
{
	char	type;
	float	x;
	float	y;
	float	w;
	float	h;
	char	c;
}	t_paint;

typedef struct s_dflt
{
	int		w;
	int		h;
	char	c;
	char	**paint;
}	t_dflt;

#endif
