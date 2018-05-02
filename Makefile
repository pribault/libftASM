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
		ft_toupper.s ft_tolower.s\
		ft_cat.s ft_strcmp.s\
		ft_memcmp.s ft_swap.s\
		ft_puts.s
TEST_SRC =	main.c benchmark.c test.c
OBJ =	$(SRC:%.s=$(OBJ_DIR)/%.o)
FORMAT =	macho64
JOBS =	4
PREFIX =	\033[0m\033[1m\033[38;5;237m[\033[38;5;239ml\033[38;5;241mi\033[38;5;243mb\033[38;5;245mf\033[38;5;247mt\033[38;5;249mA\033[38;5;251mS\033[38;5;253mM\033[38;5;255m]\033[0m 

.PHONY: all clean fclean re

all:
	@make $(NAME) -j$(JOBS)
	@make $(NAME_TEST) -j$(JOBS)
	@make ft_cat -j$(JOBS)

$(OBJ_DIR):
	@mkdir $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s $(INCLUDE_DIR)/$(INCLUDE) | $(OBJ_DIR)
	@$(CC) -f $(FORMAT) -o $@ $<
	@echo "$(PREFIX)\033[38;5;81m$(@:$(OBJ_DIR)/%.o=%.c) compiled"

$(NAME_TEST): $(TEST_SRC) $(NAME)
	@clang -I $(INCLUDE_DIR) -o $@ $(TEST_SRC) -L . -lft
	@echo "$(PREFIX)\033[38;5;221m$@ compiled"

$(NAME): $(OBJ)
	@ar rc $@ $(OBJ)
	@echo "$(PREFIX)\033[38;5;208m$@ compiled"

ft_cat: ft_cat.c $(NAME)
	@gcc -I include -o $@ $< -L . -lft
	@echo "$(PREFIX)\033[38;5;221m$@ compiled"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(PREFIX)\033[38;5;77mobject files removed"

fclean: clean
	@rm -rf $(NAME) $(NAME_TEST)
	@rm -rf ft_cat
	@echo "$(PREFIX)\033[38;5;77m$(NAME), $(NAME_TEST) and ft_cat removed"

re: fclean all
