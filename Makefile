# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmerabet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 18:07:15 by mmerabet          #+#    #+#              #
#    Updated: 2018/02/02 19:11:30 by mmerabet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

LIBFTD		=	libft
LIBFT		=	$(LIBFTD)/libft.a

MINILIBXD	=	minilibx
MINILIBX	=	$(MINILIBXD)/libmlx.a

_FDFS	=		main.c ft_keyascii.c ft_drawline.c \

SRCD		=	srcs/
ICLD		=	-Iincludes -I$(LIBFTD)/includes -I$(MINILIBXD)
FDFS		=	$(patsubst %,$(SRCD)/%,$(_FDFS))
_FDFO		=	$(_FDFS:.c=.o)
FDFO		=	$(FDFS:.c=.o)

SRCS		=	$(FDFS)
_OBJS		=	$(_FDFO)
OBJD		=	objs/
OBJS		=	$(addprefix $(SRCD),$(_OBJS))
OBJB		=	$(addprefix $(OBJD),$(_OBJS))

FRAMEWORKS	=	-framework OpenGL -framework AppKit

# COLORS
_GREY=\x1b[30m
_RED=\x1b[38;2;0;255;145m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m
_SUCCESS=$(_RED)

all: $(NAME)

$(NAME): includes/fdf.h $(LIBFT) $(MINILIBX) $(OBJB)
	@echo "$(_RED)Compiling$(_END) $(NAME)$(_RED)...$(_END)"
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJB) $(MINILIBX) $(FRAMEWORKS) -o $(NAME)
	@echo  "$(NAME) : $(_RED)done$(_END)"

$(LIBFT):
	@make -C $(LIBFTD)

$(MINILIBX):
	@make -C $(MINILIBXD)

$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	@$(CC) $(CFLAGS) -o $@ -c $< $(ICLD)

clean:
	@make -C $(LIBFTD) clean
	@make -C $(MINILIBXD) clean
	@echo "$(NAME) clean: $(_RED)done$(_END)"
	@/bin/rm -f $(OBJB)

fclean: clean
	@make -C $(LIBFTD) fclean
	@echo "$(NAME) fclean: $(_RED)done$(_END)"
	@/bin/rm -f $(NAME)

re:
	@make fclean
	@make

.PHONY: all clean fclean re
