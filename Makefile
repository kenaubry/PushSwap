# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorsin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 08:53:45 by ccorsin           #+#    #+#              #
#    Updated: 2018/04/18 18:07:25 by ccorsin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

_SRCS_P = algorithm.c \
		stacks.c \
		operations.c \
		main.c \
		fill_stack.c \
		fill_stack_str.c \
		median.c \
		short_sort.c \
		work_b.c \
		work_a.c \
		stack_tools.c \
		sort_5_elem.c \
		sort_5_index.c

_UTILS = ft_bzero.c \
		ft_strsub.c \
		ft_sort_tab.c \
		ft_atoi.c \
		ft_strdup.c

SRCS_P_DIR = push
UTILS_DIR = utils

FLAGS = -Wall -Werror -Wextra

SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
UTILS = $(addprefix $(UTILS_DIR)/, $(_UTILS))

SRCO_P = $(SRCS_P:.c=.o)
UTILSO = $(UTILS:.c=.o)

INC = -I includes/

all : $(NAME_P)

$(NAME_P) : $(SRCO_P) $(UTILSO)
	make -C printf
	@gcc $(FLAGS) -o $(NAME_P) $(SRCO_P) printf/libftprintf.a $(UTILSO)
	@echo "make done"

%.o : %.c
	@gcc -c $< -o $@ $(INC)

clean :
	@rm -rf $(SRCO_P) $(UTILSO) printf/ft_printf.o printf/type.o printf/utils.o
	@echo "clean done"

fclean : clean
	@rm -rf $(NAME_P) printf/libftprintf.a
	@echo "fclean done"

leaks : $(SRCO_P) $(UTILSO)
	make -C printf
	gcc -fsanitize=address -g3 -o $(NAME_P) $(SRCO_P) printf/libftprintf.a $(UTILSO)
	@echo "make leaks done"

re : fclean all
	@echo "make re done"

.PHONY: re clean fclean all         