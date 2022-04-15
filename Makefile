SRCS_LIST = main.c basic_hooks.c parser.c check_line.c fill_object.c fill_environ.c parse_bright.c utilities.c \
parse_coordinates.c parse_colors.c parse_vector.c free_main_struct.c parse_fov.c render.c mlx_set_color.c \
vector_utilities.c vector_utilities2.c vector_utilities3.c check_str.c add_list.c sphere_intersect.c plane_intersect.c check_intersects.c\
cylinder_intersect.c cylinder_intersect2.c

SRCS_DIR = srcs/
SRCS_DIR_BONUS = srcs_b/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))



OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))


LIBFT = libft/libft.a
HEADER = includes/mini_RT.h
HEADER_LIB = libft/libft.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB) -Imlx/mlx.h


NAME = miniRT

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
		@gcc $(CFLAGS) libft/libft.a -I /usr/local/include $(INCLUDES) $(OBJ) $(MLX) -o $(NAME)
		@echo "\n$(NAME):$(GREEN).o files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

$(LIBFT):
		@echo "$(NAME): $(GREEN)Creating libft.a...$(RESET)"
		@make -sC libft

clean:
		@echo "$(NAME):$(GREEN) libft is cleaned$(RESET)"
		@echo "$(NAME):$(GREEN) objects dirs are cleaned$(RESET)"
		@make clean -C libft
		@rm -rf objects
		@rm -rf objects_bonus


fclean: clean
		@make fclean -C libft
		@$(RM) $(NAME) $(BONUS)

re : fclean all

.PHONY: all clean fclean re