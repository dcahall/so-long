NAME		=	so_long

LIBFT_PATH	=	libft/

SRCS_PATH	=	src/

HEADER_PATH	=	includes/

LIBFT		=	libft.a

SRCS_LST		=	map_validation.c handling_errors.c find_size_of_map.c\
				creating_and_filling_map.c	so_long.c	draw_map.c\
				press_key.c

SRCS		=	$(addprefix $(SRCS_PATH), $(SRCS_LST))

HEADER		=	$(addprefix $(HEADER_PATH), so_long.h)

OBJS		=	$(patsubst %.c, %.o, $(SRCS))

CC			=	gcc

INCLUDES	=	-I$(HEADER_PATH) -I$(LIBFT_PATH) -I./minilibx

LIBFT_FLAGS	=	-L$(LIBFT_PATH) -lft

MLX_FLAGS	=	-I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit

PREPROCESSING =  -D ITS_BONUS_PROGRAMM=1

CFLAGS		=	-Wall -Wextra -Werror $(PREPROCESSING) $(INCLUDES)

RM			=	rm -f

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(HEADER)
	$(MAKE) -C $(LIBFT_PATH)
	# $(CC) $(CFLAGS) $(LIBFT_FLAGS) $(MLX_FLAGS) $(SRCS) -o $(NAME)
	$(CC) $(CFLAGS) -L$(LIBFT_PATH) -lft -I./minilibx -L./minilibx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean		:
	$(MAKE) clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean		:	clean
	$(MAKE) fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re			:	fclean all