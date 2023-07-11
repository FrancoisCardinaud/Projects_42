/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:29:23 by fcardina          #+#    #+#             */
/*   Updated: 2023/05/16 18:29:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

typedef struct s_paint
{
	char	type;
	float	x;
	float	y;
	float	r;
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
