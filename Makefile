# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 08:06:34 by dorange-          #+#    #+#              #
#    Updated: 2019/11/01 12:28:14 by dorange-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_project

PS_NAME = push_swap
CHECKER_NAME = checker

C_TX_BLACK = \033[30m
C_TX_RED = \033[31m
C_TX_GREEN = \033[32m
C_TX_YELLOW = \033[33m
C_TX_BLUE = \033[34m
C_TX_MAGENTA = \033[35m
C_TX_CYAN = \033[36m
C_TX_GREY = \033[37m

C_BG_BLACK = \033[40m
C_BG_RED = \033[41m
C_BG_GREEN = \033[42m
C_BG_YELLOW = \033[43m
C_BG_BLUE = \033[44m
C_BG_MAGENTA = \033[45m
C_BG_CYAN = \033[46m
C_BG_GREY = \033[47m

C_BASIC = \033[0m

PROJECT_TEXT = $(C_BASIC)$(C_BG_YELLOW)$(C_TX_BLACK)PUSH_SWAP:$(C_BASIC)\t
LIBFT_PROJECT_TEXT = $(C_BASIC)$(C_TX_CYAN)LIBFT:$(C_BASIC)\t
FLAGS = -Wall -Wextra -Werror

CMD_SRCS_PATH = ./src/commands/
CMD_SRCS_FILES = cmd_push.c cmd_revrotate.c cmd_rotate.c cmd_swap.c
CMD_SRCS = $(addprefix $(CMD_SRCS_PATH), $(CMD_SRCS_FILES))
CMD_OBJS_PATH = ./obj/
CMD_OBJS_FILES = $(CMD_SRCS_FILES:.c=.o)
CMD_OBJS = $(addprefix $(CMD_OBJS_PATH), $(CMD_OBJS_FILES))

ALG_SRCS_PATH = ./src/algorithm/
ALG_SRCS_FILES = core.c rotate_cycle.c rotate.c spec_alg.c swap_cycle.c \
check_rotate.c
ALG_SRCS = $(addprefix $(ALG_SRCS_PATH), $(ALG_SRCS_FILES))
ALG_OBJS_PATH = ./obj/
ALG_OBJS_FILES = $(ALG_SRCS_FILES:.c=.o)
ALG_OBJS = $(addprefix $(ALG_OBJS_PATH), $(ALG_OBJS_FILES))

FUNC_SRCS_PATH = ./src/functions/
FUNC_SRCS_FILES = debug.c get_list_count.c get_value.c lib_func.c general.c
FUNC_SRCS = $(addprefix $(FUNC_SRCS_PATH), $(FUNC_SRCS_FILES))
FUNC_OBJS_PATH = ./obj/
FUNC_OBJS_FILES = $(FUNC_SRCS_FILES:.c=.o)
FUNC_OBJS = $(addprefix $(FUNC_OBJS_PATH), $(FUNC_OBJS_FILES))

PS_SRCS_PATH = ./src/
PS_SRCS_FILES = push_swap.c
PS_SRCS = $(addprefix $(PS_SRCS_PATH), $(PS_SRCS_FILES))
PS_OBJS_PATH = ./obj/
PS_OBJS_FILES = $(PS_SRCS_FILES:.c=.o)
PS_OBJS = $(addprefix $(PS_OBJS_PATH), $(PS_OBJS_FILES))

CHECKER_SRCS_PATH = ./src/
CHECKER_SRCS_FILES = checker.c
CHECKER_SRCS = $(addprefix $(CHECKER_SRCS_PATH), $(CHECKER_SRCS_FILES))
CHECKER_OBJS_PATH = ./obj/
CHECKER_OBJS_FILES = $(CHECKER_SRCS_FILES:.c=.o)
CHECKER_OBJS = $(addprefix $(CHECKER_OBJS_PATH), $(CHECKER_OBJS_FILES))

INCLUDES = -I ./ -I ./libs/
HEADERS_PATH = ./
HEADERS_FILES = inc/push_swap.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_FILES))

all: $(NAME)

$(NAME): start $(CMD_OBJS) $(ALG_OBJS) $(FUNC_OBJS) $(CHECKER_OBJS) $(PS_OBJS) $(HEADERS)
	@make -C ./libs/
	@echo "$(PROJECT_TEXT)Build push_swap..."
	@gcc $(FLAGS) -o $(PS_NAME) $(PS_OBJS) $(CMD_OBJS) $(ALG_OBJS) $(FUNC_OBJS) ./libs/libftprintf.a -I \
	./libs/inc/libft.h -I ./libs/inc/ft_printf.h
	@gcc $(FLAGS) -o $(CHECKER_NAME) $(CHECKER_OBJS) $(FUNC_OBJS) $(CMD_OBJS) \
	./libs/libftprintf.a -I ./libs/inc/libft.h -I ./libs/inc/ft_printf.h
	@echo " "
	@echo "\033[A\033[K\033[A"
	@echo "$(PROJECT_TEXT)Finished!"

start:
	@echo "$(PROJECT_TEXT)Build libs..."

$(CHECKER_OBJS_PATH)%.o: $(PS_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(CHECKER_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(PS_OBJS_PATH)%.o: $(PS_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(PS_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(CMD_OBJS_PATH)%.o: $(CMD_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(CMD_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(ALG_OBJS_PATH)%.o: $(ALG_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(ALG_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(FUNC_OBJS_PATH)%.o: $(FUNC_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(FUNC_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -C ./libs/ clean
	@rm -fv $(CHECKER_OBJS) > /dev/null
	@rm -rf $(CHECKER_OBJS_PATH) > /dev/null

fclean: clean
	@make -C ./libs/ fclean
	@rm -fv $(NAME) > /dev/null

re: fclean all

.PHONY: clean fclean re all
