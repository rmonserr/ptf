# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 15:12:11 by rmonserr          #+#    #+#              #
#    Updated: 2020/07/01 15:23:02 by rmonserr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_PATH = src/
SRCS = ft_printf.c initialization.c parser.c parser_pt_2.c print_int.c \
print_int_pt_2.c print_char.c print_string.c print_octal.c \
print_hexadecimal.c print_pointer.c print_f.c print_f_2.c

OBJ_PATH = obj
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJS))

FT = ./libft/

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(FT)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of libftprintf:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@
	@# -l $(FT)

clean:
	@make clean -C $(FT)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "libftprintf: \033[1;32mRemoving Objs\033[m"

fclean: clean
	@make fclean -C $(FT)
	@rm -f $(NAME)
	@echo "Libftprintf: \033[1;32mRemoving Libftprintf\033[m"

re: fclean all

.PHONY: all clean fclean re
