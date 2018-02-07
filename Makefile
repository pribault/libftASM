NAME = libft.a
NAME_TEST = test
CC = nasm
SRC_DIR = src
OBJ_DIR = .obj
INCLUDE_DIR = include
SRC = ft_bzero.s
OBJ = $(SRC:%.s=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

all: $(NAME) $(NAME_TEST)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(CC) -f elf64 -o $@ $<

$(NAME_TEST): main.c $(NAME)
	gcc -I $(INCLUDE_DIR) -o $@ $< -L . -lft

$(NAME): $(OBJ)
	ar rc $@ $<

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
