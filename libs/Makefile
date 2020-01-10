# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/09 08:06:34 by dorange-          #+#    #+#              #
#    Updated: 2019/11/01 12:25:10 by dorange-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

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

PROJECT_TEXT = $(C_BASIC)$(C_TX_MAGENTA)LIBS:     $(C_BASIC)\t
FLAGS = -Wall -Wextra -Werror

PRINTF_SRCS_NAME = ft_printf
PRINTF_SRCS_PATH = ./$(PRINTF_SRCS_NAME)/
PRINTF_SRCS_FILES = ft_printf.c parse.c print.c ft_itoa_max.c float.c \
set_spec.c get_number.c number.c string.c put_str.c set_number_param.c \
color.c check_spec.c
PRINTF_SRCS = $(addprefix $(PRINTF_SRCS_PATH), $(PRINTF_SRCS_FILES))

LIB_SRCS_NAME = libft
LIB_SRCS_PATH = ./$(LIB_SRCS_NAME)/
LIB_SRCS_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstadd_fd.c \
ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_lstnew_fd.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memjoin.c ft_memmove.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strchr_rev.c \
ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strclen.c \
ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
ft_strtolower.c ft_strtoupper.c ft_strtrim.c ft_tolower.c ft_toupper.c \
get_next_line.c ft_strchr_null.c ft_strchr_control.c ft_powint.c ft_abs.c \
ft_abs_null.c ft_memalloc_exit.c ft_strnew_exit.c \
ft_lstpush.c ft_lstrevrotate.c ft_lstrotate.c ft_lstswap.c ft_lstaddnew.c \
ft_strsplit_del.c ft_atoi_int.c
LIB_SRCS = $(addprefix $(LIB_SRCS_PATH), $(LIB_SRCS_FILES))

LIB_OBJS_PATH = ./obj/
LIB_OBJS_FILES = $(LIB_SRCS_FILES:.c=.o)
LIB_OBJS = $(addprefix $(LIB_OBJS_PATH), $(LIB_OBJS_FILES))

PRINTF_OBJS_PATH = ./obj/
PRINTF_OBJS_FILES = $(PRINTF_SRCS_FILES:.c=.o)
PRINTF_OBJS = $(addprefix $(PRINTF_OBJS_PATH), $(PRINTF_OBJS_FILES))

INCLUDES = -I ./ft_printf -I ./libft -I ./inc
HEADERS_PATH = ./inc/
HEADERS_FILES = ft_printf.h libft.h
HEADERS = $(addprefix $(HEADERS_PATH), $(HEADERS_FILES))

all: $(NAME)

$(NAME): $(PRINTF_OBJS) $(LIB_OBJS) $(HEADERS)
	@ar rc $(NAME) $(PRINTF_OBJS) $(LIB_OBJS) $(LIB)
	@ranlib $(NAME)
	@echo " "
	@echo "\033[A\033[K\033[A"
	@echo "$(PROJECT_TEXT)Finished!"

$(PRINTF_OBJS_PATH)%.o: $(PRINTF_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(PRINTF_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

$(LIB_OBJS_PATH)%.o: $(LIB_SRCS_PATH)%.c
	@/bin/echo -n "."
	@mkdir $(LIB_OBJS_PATH) 2>/dev/null || echo "" > /dev/null
	@gcc $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -fv $(PRINTF_OBJS) > /dev/null
	@rm -rf $(PRINTF_OBJS_PATH) > /dev/null

fclean: clean
	@rm -fv $(NAME) > /dev/null

re: fclean all

.PHONY: clean fclean re all
