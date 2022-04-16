SRCS_LIST = main.c basic_hooks.c parser.c check_line.c fill_object.c fill_environ.c parse_bright.c utilities.c \
parse_coordinates.c parse_colors.c parse_vector.c free_main_struct.c parse_fov.c render.c mlx_set_color.c \
vector_utilities.c vector_utilities2.c vector_utilities3.c check_str.c add_list.c sphere_intersect.c plane_intersect.c check_intersects.c\
cylinder_intersect.c cylinder_intersect2.c

SRCS_B_LIST = main_bonus.c basic_hooks_bonus.c parser_bonus.c check_line_bonus.c fill_object_bonus.c fill_environ_bonus.c \
parse_bright_bonus.c utilities_bonus.c parse_coordinates_bonus.c parse_colors_bonus.c parse_vector_bonus.c \
free_main_struct_bonus.c parse_fov_bonus.c render_bonus.c mlx_set_color_bonus.c \
vector_utilities_bonus.c vector_utilities2_bonus.c vector_utilities3_bonus.c check_str_bonus.c add_list_bonus.c \
sphere_intersect_bonus.c plane_intersect_bonus.c check_intersects_bonus.c cylinder_intersect_bonus.c \
cylinder_intersect2_bonus.c

SRCS_DIR = srcs/
SRCS_DIR_BONUS = srcs_b/

SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SRCS_B = $(addprefix $(SRCS_DIR_BONUS), $(SRCS_B_LIST))


OBJ_LIST = $(patsubst %.c, %.o, $(SRCS_LIST))
OBJ_B_LIST = $(patsubst %.c, %.o, $(SRCS_B_LIST))
OBJ_DIR = objects/
OBJ_B_DIR = objects_bonus/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))
OBJ_B = $(addprefix $(OBJ_B_DIR), $(OBJ_B_LIST))


LIBFT = libft/libft.a
HEADER = includes/mini_RT.h
HEADER_B = includes_bonus/mini_RT_bonus.h
HEADER_LIB = libft/libft.h

INCLUDES = -I$(HEADER) -I$(HEADER_LIB) -Imlx/mlx.h
INCLUDES_B = -I$(HEADER_B) -I$(HEADER_LIB) -Imlx/mlx.h

NAME = miniRT

BONUS = miniRT_bonus

MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all:	$(NAME)

bonus:	$(BONUS)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
		@gcc $(CFLAGS) libft/libft.a -I /usr/local/include $(INCLUDES) $(OBJ) $(MLX) -o $(NAME)
		@echo "\n$(NAME):$(GREEN).o files were created$(RESET)"
		@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(BONUS): $(LIBFT) $(OBJ_B_DIR) $(OBJ_B)
		@gcc $(CFLAGS) libft/libft.a -I /usr/local/include $(INCLUDES_B) $(OBJ_B) $(MLX) -o $(BONUS)
		@echo "\n$(BONUS):$(GREEN).o files were created$(RESET)"
		@echo "$(BONUS): $(GREEN)$(BONUS) was created$(RESET)"

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo "$(NAME): $(GREEN)$(OBJ_DIR) was created$(RESET)"

$(OBJ_B_DIR):
		@mkdir -p $(OBJ_B_DIR)
		@echo "$(BONUS): $(GREEN)$(OBJ_B_DIR) was created$(RESET)"

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
		@echo "$(GREEN)/$(RESET)\c"

$(OBJ_B_DIR)%.o: $(SRCS_DIR_BONUS)%.c $(HEADER_B)
		@$(CC) $(CFLAGS) -c $(INCLUDES_B) $< -o $@
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