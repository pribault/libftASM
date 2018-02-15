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
		ft_isprint.s ft_isblank.s\
		ft_iscntrl.s ft_isgraph.s\
		ft_islower.s ft_isupper.s\
		ft_isspace.s ft_isxdigit.s\
		ft_whatis.s\
		ft_toupper.s ft_tolower.s\
		ft_cat.s ft_strcmp.s\
		ft_memcmp.s ft_swap.s\
		ft_puts.s\
		ft_vector_new.s ft_vector_del.s\
		ft_vector_add.s ft_vector_get.s
OBJ = $(SRC:%.s=$(OBJ_DIR)/%.o)
FORMAT = elf64

.PHONY: all clean fclean re

all: $(NAME) $(NAME_TEST) ft_cat

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INCLUDE_DIR)/$(INCLUDE) | $(OBJ_DIR)
	$(CC) -f $(FORMAT) -o $@ $<

$(NAME_TEST): main.c benchmark.c test.c $(NAME)
	clang -I $(INCLUDE_DIR) -o $@ main.c benchmark.c test.c -L . -lft

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

ft_cat: ft_cat.c $(NAME)
	gcc -I include -o $@ $< -L . -lft

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(NAME_TEST)
	rm -rf ft_cat

re: fclean all
