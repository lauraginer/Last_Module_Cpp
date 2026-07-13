# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/05 20:02:19 by lauragm           #+#    #+#              #
#    Updated: 2026/07/13 22:21:04 by lauragm          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := span
CC := c++
CPPFLAGS := -Wall -Wextra -Werror -std=c++98 -g\
		# -fsanitize=address,undefined \
		#-Wunreachable-code -Ofast \

OBJS_DIR := build

SRCS = main.cpp Span.cpp
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