NAME = so_long
NAME_B = so_long_bonus
INC = so_long.h
INCB = so_long_bonus.h
FT_PRINTF = ../ft_printf/libftprintf.a
SRCS = main.c\
		 check_error.c\
		 check_error2.c\
		 utile.c\
		 map_check.c\
		 mlx.c\
		 mlx_loop.c\
		 movement.c\
		 get_next_line.c\
		 get_next_line_utils.c\

SRCS_B = ../bonus/main_bonus.c\
		 ../bonus/check_error_bonus.c\
		 ../bonus/check_error2_bonus.c\
		 ../bonus/utile_bonus.c\
		 ../bonus/map_check_bonus.c\
		 ../bonus/mlx_bonus.c\
		 ../bonus/mlx_loop_bonus.c\
		 ../bonus/movement_bonus.c\
		 ../bonus/move_enemy.c\
		 ../bonus/mlx_put_mov.c\
		 ../bonus/enemy_bonus.c\
		 ../bonus/get_next_line.c\
		 ../bonus/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(SRCS_B:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -rf

all : $(NAME)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝"

$(NAME): $(OBJS) $(FT_PRINTF)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^

bonus: $(NAME_B)
	@echo "███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗     ████████╗"
	@echo "██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝     ██╔═══██║"
	@echo "███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗    ██████══╝"
	@echo "╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║    ██╔═══██╗"
	@echo "███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝    ████████║"
	@echo "╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝     ╚═══════╝"

$(NAME_B): $(B_OBJS)
	@$(CC) $(FLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B) $^


%.o:%.c $(INC) $(INCB)
	$(CC) $(CFLAGS) -c $< -o $@


$(FT_PRINTF): 
	make -C ../ft_printf

clean:
	$(RM) $(OBJS) $(B_OBJS)
	make -C ../ft_printf clean

fclean:clean
	$(RM) $(NAME) $(NAME_B)
	make -C../ft_printf fclean

re:fclean all