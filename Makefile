NAME = libft.a
NAME_TEST = test
CC = nasm
SRC_DIR = src
OBJ_DIR = .obj
INCLUDE_DIR = include
INCLUDE = libft_asm.h
SRC =	ft_bzero.s ft_strcat.s\
		ft_strlen.s ft_memcpy.s\
		ft_memset.s ft_strdup.s\
		ft_isalpha.s ft_isdigit.s\
		ft_isalnum.s ft_isascii.s\
		ft_isprint.s ft_puts.s\
		ft_toupper.s ft_tolower.s\
		ft_cat.s
OBJ = $(SRC:%.s=$(OBJ_DIR)/%.o)
FORMAT = macho64

.PHONY: all clean fclean re

all: $(NAME) $(NAME_TEST)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INCLUDE_DIR)/$(INCLUDE) | $(OBJ_DIR)
	$(CC) -f $(FORMAT) -o $@ $<

$(NAME_TEST): main.c $(NAME)
	gcc -I $(INCLUDE_DIR) -o $@ $< -L . -lft

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_TEST)

re: fclean all
