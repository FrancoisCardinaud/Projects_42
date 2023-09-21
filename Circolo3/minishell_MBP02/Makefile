# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 13:38:18 by fcardina          #+#    #+#              #
#    Updated: 2023/09/21 17:02:23 by fcardina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Color Aliases
DEFAULT = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SHELL=/bin/bash
UNAME = $(shell uname -s)

# Properties for MacOS
CDEBUG = #-fsanitize=address
CHECKER = tests/checker_Mac
ifeq ($(UNAME), Linux)
	#Properties for Linux
	LEAKS = valgrind --leak-check=full --track-fds=yes --trace-children=yes -s -q 
endif

# Make variables
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -MD -g3 
RM = rm -f
CC = gcc
PRINTF = printf
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
BUILTIN_DIR = $(SRC_DIR)builtin/
LEXER_DIR = $(SRC_DIR)lexer/
EXP_DIR = $(SRC_DIR)expander/
PARSER_DIR = $(SRC_DIR)parser/
EXEC_DIR = $(SRC_DIR)executor/
UTILS_DIR = $(SRC_DIR)utils/
LIBFT = libft/libft.a
BIN = minishell
NAME = $(BIN_DIR)/$(BIN)
LIBFT_DIR = libft
LIBFT_SRC = $(shell [ -d libft ] && ls libft/*.c)

#SRC = $(SRC_DIR)main.c \
$(BUILTIN_DIR)builtin_meryem.c \
$(UTILS_DIR)ft_strtrim_all.c \
exec.c \
lexer/fill_node.c \
utils/get_params.c \
utils/ft_cmdtrim.c \
expander/expand.c \
utils/heredoc.c \
utils/error.c \
env.c \
utils/custom_cmd.c \
utils/get_next_line.c \
utils/get_next_line_utils.c \
prompt/prompt.c \
utils/ft_cmdsubsplit.c \
utils/signal.c \
parser/parse_args.c \
utils/get_cmd.c

BUILTIN = builtin_meryem
ENV = env
EXEC = executor
MAIN = main
PARSING = parser
UTILS = utils
EXP = expander
LEXER = lexer
PROMPT = prompt

SRC = $(addsuffix .c, $(addprefix srcs/env/, $(ENV))) \
	  $(addsuffix .c, $(addprefix srcs/builtin/, $(BUILTIN))) \
	  $(addsuffix .c, $(addprefix srcs/executor/, $(EXEC))) \
	  $(addsuffix .c, $(addprefix srcs/main/, $(MAIN))) \
	  $(addsuffix .c, $(addprefix srcs/parser/, $(PARSER))) \
	  $(addsuffix .c, $(addprefix srcs/lexer/, $(LEXER))) \
	  $(addsuffix .c, $(addprefix srcs/prompt/, $(PROMPT))) \
	  $(addsuffix .c, $(addprefix srcs/expander/, $(EXP))) \
	  $(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \

OBJ = $(SRC:c=o)

#OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

OBJ_LFT = $(addprefix $(OBJ_LFT_DIR)/, $(SRC_LFT:.c=.o)/)

# Progress vars
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

all: $(NAME)
%.o:%.c

$(NAME): $(LIBFT) $(OBJ) | $(BIN_DIR)
	@$(CC) -L /usr/local/opt/readline/lib -I /usr/local/opt/readline/include -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include $(CFLAGS) $(CDEBUG) $(OBJ) $(LIBFT) -lreadline -o $@
	@$(PRINTF) "\r%100s\r$(GREEN)$(BIN) is up to date!$(DEFAULT)\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) -I ~/.brew/opt/readline/include -I /usr/local/opt/readline/include $(CFLAGS) $(CDEBUG) -c $< -o $@

$(LIBFT): $(LIBFT_SRC) | $(LIBFT_DIR) $(BIN_DIR)
	@make all -C libft
	@$(AR) $(NAME) $(LIBFT)

compare: all
	@cd tests && ./compare.sh && cd ..

test: all
	@cd tests && ./test.sh && cd ..

run: all
	@$(LEAKS)./$(NAME)

clean: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)Cleaning up object files in $(NAME)...$(DEFAULT)\n"
	@make clean -C libft
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) -r $(BIN_DIR)
	$(RM) $(LIBFT)
	@$(PRINTF) "$(CYAN)Removed $(LIBFT)$(DEFAULT)\n"
	@$(PRINTF) "$(CYAN)Removed $(NAME)$(DEFAULT)\n"

norminette: | $(LIBFT_DIR)
	@$(PRINTF) "$(CYAN)\nChecking norm for $(BIN)...$(DEFAULT)\n"
	@norminette -R CheckForbiddenSourceHeader $(SRC_DIR) $(INC_DIR)
	@make norminette -C libft

$(LIBFT_DIR):
	@git clone https://gitlab.com/madebypixel02/libft.git

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJB_DIR):
	@mkdir -p $(OBJB_DIR)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

re: fclean
	@make all

git:
	git add .
	git commit
	git push

-include $(OBJ_DIR)/*.d
-include $(OBJB_DIR)/*.d

.PHONY: all clean fclean norminette test compare run git re
