NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
HELPERS_DIR = $(SRC_DIR)/helper_functions
CFILES = $(SRC_DIR)/ft_printf.c $(HELPERS_DIR)/char.c $(HELPERS_DIR)/num.c $(HELPERS_DIR)/string.c
OFILES = $(OBJ_DIR)/ft_printf.o $(OBJ_DIR)/char.o $(OBJ_DIR)/num.o $(OBJ_DIR)/string.o

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(HELPERS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OFILES)
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re