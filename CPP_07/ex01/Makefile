# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/15 16:06:21 by lginer-m          #+#    #+#              #
#    Updated: 2026/05/05 18:49:52 by lginer-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := iter
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -g\
		# -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \

OBJS_DIR := build

SRCS = main.cpp
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

BLUE = \033[0;34m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)🔗 Linking $(NAME)...$(RESET)"
	@$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ $(NAME) created!$(RESET)"

$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(BLUE)🧹 Object files cleaned!$(RESET)"
    
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🔥 $(NAME) has been deleted!$(RESET)"

re: fclean all

debug: CPPFLAGS += -g -O0 -fsanitize=address,undefined
debug: re