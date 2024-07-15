#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              HEADERS
*/
# include "libft.h"
# include <limits.h>

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              MACROS
*/
# define READL_OK		1
# define EOF_RCHD		0
# define HPND		-1

# define NO_ENDLINE		0
# define FOUND_ENDLINE	1

# define BUFFER_SIZE	128

# ifdef __linux__
#  define OPEN_MAX		1024
#  define ARG_MAX		2097152
# endif

/*
** -.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-.-'-
**                              FUNCTION PROTOTYPES
*/
char		*get_next_line(int fd);

#endif