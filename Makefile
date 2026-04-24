# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eric <eric@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/22 17:00:00 by eric             #+#    #+#              #
#    Updated: 2026/04/22 17:00:00 by eric            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# VARIABLES
# ============================================================================ #

# Compiler and flags
CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -I./inc
CFLAGS_DBG	:= $(CFLAGS) -g -DDEBUG
LDFLAGS		:=

# Directories
SRC_DIR		:= src
LIBFT_DIR	:= libft
OBJ_DIR		:= obj
INC_DIR		:= inc

# Files
TARGET		:= ft_ssl
SRC_FILES	:= main.c engine.c init.c md5_algo.c padding.c parsing.c utils.c
LIBFT_FILES	:= ft_atoi.c ft_memcmp.c ft_memcpy.c ft_memset.c ft_strcmp.c ft_strdup.c ft_strlen.c

# Object files
SRC_OBJ		:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIBFT_OBJ	:= $(addprefix $(OBJ_DIR)/, $(LIBFT_FILES:.c=.o))
OBJ			:= $(SRC_OBJ) $(LIBFT_OBJ)

# Colors for output
RED			:= \033[0;31m
GREEN		:= \033[0;32m
YELLOW		:= \033[0;33m
BLUE		:= \033[0;34m
NC			:= \033[0m

# ============================================================================ #
# RULES
# ============================================================================ #

.PHONY: all clean fclean re debug help

all: $(OBJ_DIR) $(TARGET)

# Main target
$(TARGET): $(OBJ)
	@echo "$(BLUE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NC)"
	@echo "$(BLUE)   Linking...$(NC)"
	@echo "$(BLUE)━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━$(NC)"
	@$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "$(GREEN)✓ $(TARGET) compiled successfully!$(NC)"
	@echo ""

# Object directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Compile source files from src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(YELLOW)Compiling$(NC) $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Compile libft files
$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c
	@echo "$(YELLOW)Compiling$(NC) $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

# Debug build
debug: CFLAGS = $(CFLAGS_DBG)
debug: fclean $(TARGET)
	@echo "$(BLUE)Debug build completed$(NC)"

# Clean object files
clean:
	@echo "$(YELLOW)Cleaning object files...$(NC)"
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)✓ Clean complete$(NC)"

# Clean everything
fclean: clean
	@echo "$(YELLOW)Removing executable...$(NC)"
	@rm -f $(TARGET)
	@echo "$(GREEN)✓ Full clean complete$(NC)"

# Rebuild
re: fclean all

# Help
help:
	@echo "$(BLUE)╔════════════════════════════════════╗$(NC)"
	@echo "$(BLUE)║     ft_ssl_md5 - Makefile Help     ║$(NC)"
	@echo "$(BLUE)╚════════════════════════════════════╝$(NC)"
	@echo ""
	@echo "$(GREEN)Available targets:$(NC)"
	@echo "  $(YELLOW)all$(NC)       - Compile the project"
	@echo "  $(YELLOW)debug$(NC)     - Compile with debug symbols"
	@echo "  $(YELLOW)clean$(NC)     - Remove object files"
	@echo "  $(YELLOW)fclean$(NC)    - Remove object files and executable"
	@echo "  $(YELLOW)re$(NC)        - Rebuild the project"
	@echo "  $(YELLOW)help$(NC)      - Display this help message"
	@echo ""
