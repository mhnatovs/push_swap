# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhnatovs <mhnatovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 16:41:11 by mhnatovs          #+#    #+#              #
#    Updated: 2025/10/18 14:36:18 by mhnatovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

SRC			= index.c \
				is_sorted.c \
				parsing.c \
				operations_push.c \
				operations_swap.c \
				operations_rotate.c \
				operations_reverse_rotate.c \
				push_swap.c \
				sort_five.c \
				sort_more.c \
				stack_utils.c \
				sort_utils.c \
				sort_utils2.c

LIBFT_DIR		= ./libft
LIBFT			= $(LIBFT_DIR)/libft.a

OBJ				= $(SRC:.c=.o)

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -I.$(LIBFT_DIR)

all:			$(NAME)

$(NAME):		$(OBJ)
		$(MAKE) -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
		$(MAKE) -C $(LIBFT_DIR) clean
		rm -f $(OBJ)

fclean:			clean
		$(MAKE) -C $(LIBFT_DIR) fclean
		rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re