# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:05:39 by lrichard          #+#    #+#              #
#    Updated: 2021/10/05 18:38:26 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

SRCSDIR					= sources

SRCS					= main.c get_file.c parse_file.c \
						  parse_map.c utils.c mlxstuff.c \
						  controls.c raycasting.c display.c \
						  antisegf.c

OBJS					= $(addprefix $(SRCSDIR)/, $(SRCS:.c=.o))

SRCSBONUSDIR			= BONUS/sources

SRCSBONUS				= main_bonus.c get_file_bonus.c \
						  parse_file_bonus.c parse_map_bonus.c \
						  utils_bonus.c controls_bonus.c \
						  mlxstuff_bonus.c raycasting_bonus.c \
						  display_bonus.c \
					 	  collisions_bonus.c crosshair_bonus.c

OBJSBONUS				= $(addprefix $(SRCSBONUSDIR)/, $(SRCSBONUS:.c=.o))

HEADERSDIR				= includes

HEADERS					= $(HEADERSDIR)/cub3d.h

HEADERSBONUSDIR			= BONUS/includes

HEADERSBONUS			= $(HEADERSBONUSDIR)/cub3d_bonus.h

LIBFTHDIR				= LIBFT

MLXHDIR					= MLX

$(SRCSDIR)/%.o: 		$(SRCSDIR)/%.c	$(HEADERS)
						$(CC) $(CFLAGS) -I $(HEADERSDIR) -I $(LIBFTHDIR) -I $(MLXHDIR) -c $< -o $@

$(SRCSBONUSDIR)/%.o:	$(SRCSBONUSDIR)/%.c $(HEADERSBONUS)
						$(CC) $(CFLAGS) -I $(HEADERSBONUSDIR) -I $(LIBFTHDIR) -I $(MLXHDIR) -c $< -o $@

LIBFTA					= LIBFT/libft.a

MLXA					= MLX/libmlx.a

NAME					= cub3D

CFLAGS					= -Wall -Wextra -Werror -I MLX -O3 -march=native

CC						= gcc

RM						= rm -f

all:					mklibfta $(NAME)

mklibfta:
						$(MAKE) -C ./LIBFT

$(NAME):				$(OBJS) $(LIBFTA) $(MLXA) $(HEADERS)
						$(CC) $(CFLAGS) $(OBJS) $(LIBFTA) $(MLXA) -I $(HEADERSDIR) -I $(LIBFTHDIR) -I $(MLXHDIR) -L MLX -l MLX -framework OpenGL -framework AppKit -o $@

bonus:					mklibfta BONUS/$(NAME)

BONUS/$(NAME):			$(OBJSBONUS) $(LIBFTA) $(MLXA) $(HEADERSBONUS)
						$(CC) $(CFLAGS) $(OBJSBONUS) $(LIBFTA) $(MLXA) -I $(HEADERSBONUSDIR) -I $(LIBFTHDIR) -I $(MLXHDIR) -L MLX -l MLX -framework OpenGL -framework AppKit -o $@

clean:
						$(RM) $(OBJS) $(OBJSBONUS)

fclean:					clean
						$(RM) $(NAME) BONUS/$(NAME)

re:						fclean all

.PHONY:					mklibfta bonus all clean fclean re
