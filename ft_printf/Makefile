NAME = libftprintf.a
INC = ft_printf.h
SRCE = ft_printf.c\
		ft_printchar.c\
		ft_printstr.c\
		ft_printint.c\
		ft_printusg.c\
		ft_printhexa.c\
		ft_printupphexa.c\
		ft_printptr.c

OBJS = $(SRCE:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = @rm -rf
AR = @ar -rcs

all : $(NAME)

$(NAME):$(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o:%.c
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all