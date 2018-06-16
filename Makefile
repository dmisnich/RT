# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmisnich <dmisnich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/18 12:37:43 by dmisnich          #+#    #+#              #
#    Updated: 2018/01/26 11:39:24 by dmisnich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

CFLAGS = -I ./include/ -I Frameworks/SDL2.framework/Headers

SRCS =	src/main/main.c \
		src/main/find_obj_normal.c \
		src/main/solve_discrim.c \
		src/main/vector_operation.c \
		src/main/vector_operation2.c \
		src/main/ray.c \
		src/misc/protect.c \
		src/misc/color.c \
		src/misc/key.c \
		src/misc/init_one.c \
		src/misc/init_two.c \
		src/objects/spot.c \
		src/objects/sphere.c \
		src/objects/plane.c \
		src/objects/cylindre.c \
		src/objects/cone.c \
		new/objects/ellips.c \
		new/objects/paraboloid.c \
		new/objects/cylindre_cut.c \
		new/objects/cone_cut.c \
		src/scene/scene_6_sphere.c \
		src/scene/scene_6_plane.c \
		src/scene/scene_6_cylindre.c \
		src/scene/help_init_scene2.c \
		src/scene/help_init_scene.c \

OBJ = $(SRCS:.c=.o)

#libft
LFT_DIR = ./libft/
LFT_LNK = -L $(LFT_DIR) -lft

#sdl
SDL_LNK = -framework SDL2 -F ./Frameworks/
SDL2_P	= -rpath @loader_path/Frameworks/

all: $(NAME)

debug:
	$(CC) $(CFLAGS) -g -o $(NAME) $(SRCS) $(LFT_LNK) $(SDL_LNK)
derun: debug
	lldb ./$(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_DIR)
	@$(CC) -o $(NAME) $(FLAGS) $(CFLAGS) $(SDL2_P) $(SDL_LNK) $(LFT_LNK) $(OBJ) -g

clean:
	@make -C $(LFT_DIR) clean
	@rm -f src/*.o
	@rm -f src/objects/*.o
	@rm -f src/scene/*.o
	@rm -f src/main/*.o
	@rm -f src/misc/*.o
	@rm -rf ./*.dSYM

norme:
	@echo "|--------------------------------------------------|"
	@echo "|-------------------Checking header files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./include
	@echo "|--------------------------------------------------|"
	@echo "--------------------Checking source files fractol--|"
	@echo "|--------------------------------------------------|"
	@norminette ./src

fclean: clean
	@make -C $(LFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.SILENT:
