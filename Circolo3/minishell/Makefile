#  |  |  ___ \    \  |         |
#  |  |     ) |  |\/ |   _  |  |  /   _ 
# ___ __|  __/   |   |  (   |    <    __/ 
#    _|  _____| _|  _| \__,_| _|\_\ \___|
#                              by jcluzet
################################################################################
#                                     CONFIG                                   #
################################################################################

NAME        := minishell
CC        := gcc
FLAGS    := -Wall -Wextra -Werror 
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      lexer/lexer.c \
                          utils/libft/ft_strnstr.c \
                          utils/libft/ft_lstadd_back \
                          c \
                          utils/libft/ft_strnstr \
                          c \
                          utils/libft/ft_strdup \
                          c \
                          utils/libft/ft_bzero \
                          c \
                          utils/libft/ft_striteri \
                          c \
                          utils/libft/ft_isdigit.c \
                          utils/libft/ft_lstadd_back.c \
                          utils/libft/ft_putstr_fd.c \
                          utils/libft/ft_putchar_fd \
                          c \
                          utils/libft/ft_memcpy \
                          c \
                          utils/libft/ft_strtrim \
                          c \
                          utils/libft/ft_lstnew.c \
                          utils/libft/ft_split \
                          c \
                          utils/libft/ft_strlcpy.c \
                          utils/libft/ft_strlen.c \
                          utils/libft/ft_atoi \
                          c \
                          utils/libft/ft_lstlast.c \
                          utils/libft/ft_memcmp.c \
                          utils/libft/ft_strjoin \
                          c \
                          utils/libft/ft_putnbr_fd.c \
                          utils/libft/ft_lstclear.c \
                          utils/libft/ft_lstiter.c \
                          utils/libft/ft_strchr.c \
                          utils/libft/ft_lstmap \
                          c \
                          utils/libft/ft_lstclear \
                          c \
                          utils/libft/ft_isascii \
                          c \
                          utils/libft/ft_striteri.c \
                          utils/libft/ft_bzero.c \
                          utils/libft/ft_strmapi \
                          c \
                          utils/libft/ft_memset \
                          c \
                          utils/libft/ft_strjoin.c \
                          utils/libft/ft_isascii.c \
                          utils/libft/ft_strrchr \
                          c \
                          utils/libft/ft_lstlast \
                          c \
                          utils/libft/ft_memcpy.c \
                          utils/libft/ft_strcmp \
                          c \
                          utils/libft/ft_isnbr \
                          c \
                          utils/libft/ft_isprint \
                          c \
                          utils/libft/ft_memcmp \
                          c \
                          utils/libft/ft_isprint.c \
                          utils/libft/ft_putstr_fd \
                          c \
                          utils/libft/ft_putendl_fd.c \
                          utils/libft/ft_lstmap.c \
                          utils/libft/ft_isdigit \
                          c \
                          utils/libft/ft_lstsize.c \
                          utils/libft/ft_toupper.c \
                          utils/libft/ft_substr \
                          c \
                          utils/libft/ft_strncmp \
                          c \
                          utils/libft/ft_split.c \
                          utils/libft/ft_lstadd_front.c \
                          utils/libft/ft_strrchr.c \
                          utils/libft/ft_lstadd_front \
                          c \
                          utils/libft/ft_memmove \
                          c \
                          utils/libft/ft_isalpha.c \
                          utils/libft/ft_lstiter \
                          c \
                          utils/libft/ft_memchr.c \
                          utils/libft/ft_putchar_fd.c \
                          utils/libft/ft_memset.c \
                          utils/libft/ft_substr.c \
                          utils/libft/ft_strncmp.c \
                          utils/libft/ft_itoa \
                          c \
                          utils/libft/ft_strlcat \
                          c \
                          utils/libft/ft_toupper \
                          c \
                          utils/libft/ft_strlen \
                          c \
                          utils/libft/ft_lstnew \
                          c \
                          utils/libft/ft_isalpha \
                          c \
                          utils/libft/ft_isalnum \
                          c \
                          utils/libft/ft_strmapi.c \
                          utils/libft/ft_strtrim.c \
                          utils/libft/ft_calloc \
                          c \
                          utils/libft/ft_putnbr_fd \
                          c \
                          utils/libft/ft_memmove.c \
                          utils/libft/ft_lstsize \
                          c \
                          utils/libft/ft_putendl_fd \
                          c \
                          utils/libft/ft_tolower \
                          c \
                          utils/libft/ft_strlcat.c \
                          utils/libft/ft_calloc.c \
                          utils/libft/ft_lstdelone \
                          c \
                          utils/libft/ft_memchr \
                          c \
                          utils/libft/ft_isnbr.c \
                          utils/libft/ft_strdup.c \
                          utils/libft/ft_strchr \
                          c \
                          utils/libft/ft_atoi.c \
                          utils/libft/ft_isalnum.c \
                          utils/libft/ft_lstdelone.c \
                          utils/libft/ft_itoa.c \
                          utils/libft/ft_strlcpy \
                          c \
                          utils/libft/ft_tolower.c \
                          utils/libft/ft_strcmp.c \
                          utils/ft_printf/ft_print_unsigned \
                          c \
                          utils/ft_printf/ft_printf_utils.c \
                          utils/ft_printf/ft_print_ptr \
                          c \
                          utils/ft_printf/ft_print_hex \
                          c \
                          utils/ft_printf/ft_printf.c \
                          utils/ft_printf/ft_printf \
                          c \
                          utils/ft_printf/libft/ft_strnstr.c \
                          utils/ft_printf/libft/ft_lstadd_back \
                          c \
                          utils/ft_printf/libft/ft_strnstr \
                          c \
                          utils/ft_printf/libft/ft_strdup \
                          c \
                          utils/ft_printf/libft/ft_bzero \
                          c \
                          utils/ft_printf/libft/ft_striteri \
                          c \
                          utils/ft_printf/libft/ft_isdigit.c \
                          utils/ft_printf/libft/ft_lstadd_back.c \
                          utils/ft_printf/libft/ft_putstr_fd.c \
                          utils/ft_printf/libft/ft_putchar_fd \
                          c \
                          utils/ft_printf/libft/ft_memcpy \
                          c \
                          utils/ft_printf/libft/ft_strtrim \
                          c \
                          utils/ft_printf/libft/ft_lstnew.c \
                          utils/ft_printf/libft/ft_split \
                          c \
                          utils/ft_printf/libft/ft_strlcpy.c \
                          utils/ft_printf/libft/ft_strlen.c \
                          utils/ft_printf/libft/ft_atoi \
                          c \
                          utils/ft_printf/libft/ft_lstlast.c \
                          utils/ft_printf/libft/ft_memcmp.c \
                          utils/ft_printf/libft/ft_strjoin \
                          c \
                          utils/ft_printf/libft/ft_putnbr_fd.c \
                          utils/ft_printf/libft/ft_lstclear.c \
                          utils/ft_printf/libft/ft_lstiter.c \
                          utils/ft_printf/libft/ft_strchr.c \
                          utils/ft_printf/libft/ft_lstmap \
                          c \
                          utils/ft_printf/libft/ft_lstclear \
                          c \
                          utils/ft_printf/libft/ft_isascii \
                          c \
                          utils/ft_printf/libft/ft_striteri.c \
                          utils/ft_printf/libft/ft_bzero.c \
                          utils/ft_printf/libft/ft_strmapi \
                          c \
                          utils/ft_printf/libft/ft_memset \
                          c \
                          utils/ft_printf/libft/ft_strjoin.c \
                          utils/ft_printf/libft/ft_isascii.c \
                          utils/ft_printf/libft/ft_strrchr \
                          c \
                          utils/ft_printf/libft/ft_lstlast \
                          c \
                          utils/ft_printf/libft/ft_memcpy.c \
                          utils/ft_printf/libft/ft_strcmp \
                          c \
                          utils/ft_printf/libft/ft_isprint \
                          c \
                          utils/ft_printf/libft/ft_memcmp \
                          c \
                          utils/ft_printf/libft/ft_isprint.c \
                          utils/ft_printf/libft/ft_putstr_fd \
                          c \
                          utils/ft_printf/libft/ft_putendl_fd.c \
                          utils/ft_printf/libft/ft_lstmap.c \
                          utils/ft_printf/libft/ft_isdigit \
                          c \
                          utils/ft_printf/libft/ft_lstsize.c \
                          utils/ft_printf/libft/ft_toupper.c \
                          utils/ft_printf/libft/ft_substr \
                          c \
                          utils/ft_printf/libft/ft_strncmp \
                          c \
                          utils/ft_printf/libft/ft_split.c \
                          utils/ft_printf/libft/ft_lstadd_front.c \
                          utils/ft_printf/libft/ft_strrchr.c \
                          utils/ft_printf/libft/ft_lstadd_front \
                          c \
                          utils/ft_printf/libft/ft_memmove \
                          c \
                          utils/ft_printf/libft/ft_isalpha.c \
                          utils/ft_printf/libft/ft_lstiter \
                          c \
                          utils/ft_printf/libft/ft_memchr.c \
                          utils/ft_printf/libft/ft_putchar_fd.c \
                          utils/ft_printf/libft/ft_memset.c \
                          utils/ft_printf/libft/ft_substr.c \
                          utils/ft_printf/libft/ft_strncmp.c \
                          utils/ft_printf/libft/ft_itoa \
                          c \
                          utils/ft_printf/libft/ft_strlcat \
                          c \
                          utils/ft_printf/libft/ft_toupper \
                          c \
                          utils/ft_printf/libft/ft_strlen \
                          c \
                          utils/ft_printf/libft/ft_lstnew \
                          c \
                          utils/ft_printf/libft/ft_isalpha \
                          c \
                          utils/ft_printf/libft/ft_isalnum \
                          c \
                          utils/ft_printf/libft/ft_strmapi.c \
                          utils/ft_printf/libft/ft_strtrim.c \
                          utils/ft_printf/libft/ft_calloc \
                          c \
                          utils/ft_printf/libft/ft_putnbr_fd \
                          c \
                          utils/ft_printf/libft/ft_memmove.c \
                          utils/ft_printf/libft/ft_lstsize \
                          c \
                          utils/ft_printf/libft/ft_putendl_fd \
                          c \
                          utils/ft_printf/libft/ft_tolower \
                          c \
                          utils/ft_printf/libft/ft_strlcat.c \
                          utils/ft_printf/libft/ft_calloc.c \
                          utils/ft_printf/libft/ft_lstdelone \
                          c \
                          utils/ft_printf/libft/ft_memchr \
                          c \
                          utils/ft_printf/libft/ft_strdup.c \
                          utils/ft_printf/libft/ft_strchr \
                          c \
                          utils/ft_printf/libft/ft_atoi.c \
                          utils/ft_printf/libft/ft_isalnum.c \
                          utils/ft_printf/libft/ft_lstdelone.c \
                          utils/ft_printf/libft/ft_itoa.c \
                          utils/ft_printf/libft/ft_strlcpy \
                          c \
                          utils/ft_printf/libft/ft_tolower.c \
                          utils/ft_printf/libft/ft_strcmp.c \
                          utils/ft_printf/ft_printf_utils \
                          c \
                          utils/ft_printf/ft_print_ptr.c \
                          utils/ft_printf/ft_print_unsigned.c \
                          utils/ft_printf/ft_print_hex.c \
                          utils/lexer_utils.c \
                          parser_meryem/setenv.c \
                          parser_meryem/handle_error.c \
                          parser_meryem/main.c \
                          
OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		all

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re


