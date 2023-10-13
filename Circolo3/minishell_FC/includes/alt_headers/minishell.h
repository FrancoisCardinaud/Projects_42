#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/inc/libft.h"
# include "colors.h"
# include "utils/get_next_line.h"
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <sys/ioctl.h>

# include "builtin.h"
# include "utils.h"
# include "signals.h"
# include "types.h"

# define READ_END 0
# define WRITE_END 1

#endif
