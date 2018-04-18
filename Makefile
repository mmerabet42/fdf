# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 18:07:15 by mmerabet          #+#    #+#              #
#    Updated: 2018/04/01 20:37:49 by mmerabet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -g -fsanitize=address

LIBFTD		=	libft
LIBFT		=	$(LIBFTD)/libft.a

MINILIBXD	=	minilibx
MINILIBX	=	$(MINILIBXD)/libmlx.a

_NTS	=		main.c ft_keyascii.c ft_drawline.c ft_getmodel.c \
				ft_transform_model.c buffer.c \

SRCD		=	srcs/
ICLD		=	-Iincludes -I$(LIBFTD)/includes
NTS			=	$(patsubst %,$(SRCD)/%,$(_NTS))
_NTO		=	$(_NTS:.c=.o)
NTO			=	$(NTS:.c=.o)

SRCS		=	$(NTS)
_OBJS		=	$(_NTO)
OBJD		=	objs/
OBJS		=	$(addprefix $(SRCD),$(_OBJS))
OBJB		=	$(addprefix $(OBJD),$(_OBJS))

FRAMEWORKS	=	-framework OpenGL -framework AppKit

# COLORS
CRED=\033[91m
CGREEN=\033[38;2;0;255;145m
CEND=\033[0m

all: lib $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJB)
	@printf "\r\033[K$(CGREEN)Creating executable$(CEND): $(NAME)\n"
	@$(CC) $(CFLAGS) $(OBJB) $(LIBFT) $(MINILIBX) $(FRAMEWORKS) -o $(NAME)
	@echo  "$(NAME): $(CGREEN)done$(CEND)"

lib:
	@make -C $(LIBFTD)

$(MINILIBX):
	@make -C $(MINILIBXD)

$(OBJD)%.o: $(SRCD)%.c includes/fdf.h
	@printf "\r\033[K$(CGREEN)Compiling$(CEND): $@"
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< $(ICLD)

clean:
	@make -C $(LIBFTD) clean
	@echo "$(CRED)Cleaning$(CEND): $(NAME)"
	@rm -f $(OBJB)

fclean: clean
	@make -C $(LIBFTD) fclean
	@echo "$(CRED)Full cleaning$(CEND): $(NAME)"
	@/bin/rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean re
