NAME = libft.a

SRC_PATH = src
SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putchar.c ft_putendl.c ft_putendl_fd.c  ft_putstr.c \
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
ft_strncat.c ft_strncmp.c ft_strncpy.c  ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstmap.c ft_lstiter.c \
ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_revstring.c ft_isspace.c ft_word_count.c

#ft_putnbr_fd.c
#ft_putnbr.c

OBJ_PATH = obj
OBJS = $(SRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes
SRC = $(addprefix $(SRC_PATH)/,$(SRCS))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compilation of libft:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(FLAGS) -c $< $(INCLUDES) -o $@

clean:
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "libft: \033[1;32mRemoving Objs\033[m"

fclean: clean
	@rm -f $(NAME)
	@echo "Libft: \033[1;32mRemoving Libft\033[m"

re: fclean all

.PHONY: all clean fclean re
