# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <anolivei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/25 15:06:33 by anolivei          #+#    #+#              #
#    Updated: 2021/07/25 15:07:42 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC_DIR = sources
OBJ_DIR = .objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC =	$(SRC_DIR)/main.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -L ./$(LIBFT_DIR) -lft
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

$(LIBFT):
		@make -C $(LIBFT_DIR)

debug_mac: $(OBJ) $(LIBFT)
		@gcc $(LFLAGS) $(HEAD) $(SRC) $(CFLAGS) -o "minishell_debug"

debug_linux:
		@gdd $(LFLAGS) $(HEAD) $(SRC) $(CFLAGS) -o "minishell_debug"

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJ_DIR)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) $(NAME)
		@$(RM) minishell_debug
		@$(RM) minishell_debug.dSYM

re: fclean all

.PONY: all clean fclean re debug_mac debug_linux