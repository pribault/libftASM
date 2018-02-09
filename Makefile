NAME = libft.a
NAME_TEST = test
CC = nasm
SRC_DIR = src
OBJ_DIR = .obj
INCLUDE_DIR = include
SRC =	ft_bzero.s ft_strcat.s\
		ft_strlen.s ft_memcpy.s\
		ft_memset.s ft_strdup.s\
		ft_isalpha.s
OBJ = $(SRC:%.s=$(OBJ_DIR)/%.o)
FORMAT = elf64

.PHONY: all clean fclean re

all: $(NAME) $(NAME_TEST)

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s | $(OBJ_DIR)
	$(CC) -f $(FORMAT) -o $@ $<

$(NAME_TEST): main.c $(NAME)
	clang -I $(INCLUDE_DIR) -o $@ $< -L . -lft

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_TEST)

re: fclean all
