# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 16:05:39 by lrichard          #+#    #+#              #
#    Updated: 2021/06/23 16:31:47 by lrichard         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #
SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c absf.c \
			  		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c \
						ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
							nmalloc.c nealloc.c gnl.c arglen.c ft_strlenc.c intlen.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
					ft_putendl_fd.c ft_putnbr_fd.c \
				printc.c prints.c prints_np.c printn.c ft_abs.c ft_factorial.c ft_power.c ft_sqrt.c isprime.c nextprime.c vnorm.c vadd.c vrotate.c \
					ft_strcpy.c ft_strcat.c ft_strcchr.c ft_strstr.c ft_strcase.c ft_strcmp.c tablen.c ft_sort_strtab.c sq.c \
						atoi_base.c itoa_base.c ft_checkbase.c ft_convbase.c \
				lstnew.c lstadd_front.c lstlen.c lstlast.c lstadd.c lstdelone.c lstclear.c lstiter.c lstmap.c \

OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

CC			= gcc
RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

%.o: 		%.c libft.h
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			ar rcs $(NAME) $?

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
