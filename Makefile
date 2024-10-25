NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I include
SRC_DIR = src
OBJ_DIR = obj
DIRECTORIES = obj/helper_functions
CFILES = $(SRC_DIR)/ft_printf.c \
		$(SRC_DIR)/helper_functions/ft_putchar.c \
		$(SRC_DIR)/helper_functions/ft_putnbr.c \
		$(SRC_DIR)/helper_functions/ft_putnbr_unsigned.c \
		$(SRC_DIR)/helper_functions/ft_putstr.c \
		$(SRC_DIR)/helper_functions/print_address.c \
		$(SRC_DIR)/helper_functions/uppercase_hex.c \
		$(SRC_DIR)/helper_functions/convert_to_hex.c
OFILES = $(OBJ_DIR)/ft_printf.o \
		$(OBJ_DIR)/helper_functions/ft_putchar.o \
		$(OBJ_DIR)/helper_functions/ft_putnbr.o \
		$(OBJ_DIR)/helper_functions/ft_putnbr_unsigned.o \
		$(OBJ_DIR)/helper_functions/ft_putstr.o \
		$(OBJ_DIR)/helper_functions/print_address.o \
		$(OBJ_DIR)/helper_functions/uppercase_hex.o \
		$(OBJ_DIR)/helper_functions/convert_to_hex.o

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(DIRECTORIES)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(DIRECTORIES):
	mkdir -p $(DIRECTORIES)

clean:
	rm -f $(OFILES)
	rm -rf $(OBJ_DIR)

fclean: clean 
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re