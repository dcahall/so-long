NAME		=	so_long

LIBFT_PATH	=	libft/

SRCS_PATH	=	src/

BONUS_PATH	=	bonus/

HEADER_PATH	=	includes/

LIBFT		=	libft.a

SRCS_LST	=	map_validation.c			handling_errors_and_print_fun.c	find_size_of_map.c\
				creating_and_filling_map.c	so_long.c						draw_map.c\
				press_key.c					

B_SRC		=	player_animation.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LST))

B_SRCS		=	$(addprefix $(BONUS_PATH), $(B_SRC))

HEADER		=	$(addprefix $(HEADER_PATH), so_long.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

B_OBJS		=	$(patsubst %.c, %.o, $(B_SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIBFT_PATH) -I./minilibx

LIBFT_FLAGS	=	-L$(LIBFT_PATH) -lft

MLX_FLAGS	=	-I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit

PREPROCESSING =  -D ITS_BONUS_PROGRAMM=1

CFLAGS		=	-Wall -Wextra -Werror $(PREPROCESSING) $(INCLUDES)

RM			=	rm -f

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER) $(B_OBJS)
	$(MAKE) -C $(LIBFT_PATH)
	# $(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SRCS) -o $(NAME)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit $(SRCS) $(B_SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re			:	fclean all