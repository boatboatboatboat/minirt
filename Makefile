# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dpattij <dpattij@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/07 01:15:55 by dpattij        #+#    #+#                 #
#    Updated: 2020/01/11 02:41:57 by dpattij          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

FLAGS_RELEASE = -Wall -Wextra -Werror -O3 -g
CONFIG_FLAGS = -D IS_BONUS=0 -D THREAD_COUNT=1

INCLUDE_DIR = ./include/
FT_DIR = ./libft/
FT_INCLUDE_DIR = $(FT_DIR)
FT_ARCHIVE = $(FT_DIR)/libft.a
MLX_DIR = ./minilibx/
MLX_LIB = $(MLX_DIR)/libmlx.dylib

OBJ_DIR = ./obj/
SRC_DIR = ./src/

SRC_FILES =	main \
			error

VEC3_FILES =	new \
				zero \
				dot \
				cross \
				norm \
				magnitude \
				unit \
				add \
				sub \
				mul \
				div \
				unm \
				mulf \
				divf \
				up \
				forward \
				right
VEC3_FILES := $(VEC3_FILES:%=vec3/vec3_%)

MAT4_FILES =	zero \
				new \
				lookat \
				mul_rbx \
				right_vec \
				up_vec \
				look_vec \
				pos \
				identity \
				inverse \
				mulv_dir \
				mul \
				angles \
				addv
MAT4_FILES := $(MAT4_FILES:%=mat4/mat4_%)

DSTRING_FILES =	new \
				push_str \
				pushn
DSTRING_FILES := $(DSTRING_FILES:%=string/dstring_%)

PARSER_FILES =	cb_resolution \
				cb_scene \
				cb_sphere \
				cb_square \
				cb_plane \
				cb_triangle \
				cb_ambient \
				cb_cylinder \
				cb_color \
				cb_camera \
				cb_light \
				cb_vector \
				expect \
				parse_from_file \
				skip_atleast \
				take_number \
				take_f64
PARSER_FILES := $(PARSER_FILES:%=parser/%)

VECTOR_FILES :=	get \
				getr \
				new \
				pop \
				push \
				resize \
				set \
				with_capacity \
				destroy
VECTOR_FILES := $(VECTOR_FILES:%=vector/vector_%)

SCENE_FILES :=	scene_render \
				scene_cast_ray \
				ray_new \
				screen_ray \
				render_pixel \
				sphere \
				square \
				cylinder \
				triangle \
				plane \
				color
SCENE_FILES := $(SCENE_FILES:%=scene/%)

INTERACTION_FILES :=	decrease_fov \
						increase_fov \
						move_back \
						move_left \
						move_right \
						move_forward \
						move_down_world \
						move_up_world \
						pitch_up \
						pitch_down \
						roll_left \
						roll_right \
						rotate_left \
						rotate_right \
						next_camera \
						prev_camera \
						change_obj_size \
						change_obj_pos \
						change_obj_rot \
						obj_pos_addx \
						obj_pos_subx \
						obj_pos_addy \
						obj_pos_suby \
						obj_pos_addz \
						obj_pos_subz \
						obj_rot_addx \
						obj_rot_subx \
						obj_rot_addy \
						obj_rot_suby \
						obj_rot_addz \
						obj_rot_subz \
						change_scale \
						exit_program
INTERACTION_FILES := $(INTERACTION_FILES:%=interaction/%)

MISC_FILES :=	degrad \
				solve_quad \
				setup_drawer \
				canvas_put_pixel \
				drawer_destroy
MISC_FILES := $(MISC_FILES:%=misc/%)

BMP_FILES :=	output_bmp
BMP_FILES := $(BMP_FILES:%=bmp/%)

SRC_FILES +=	$(VEC3_FILES) \
				$(MAT4_FILES) \
				$(DSTRING_FILES) \
				$(PARSER_FILES) \
				$(VECTOR_FILES) \
				$(SCENE_FILES) \
				$(INTERACTION_FILES) \
				$(MISC_FILES) \
				$(BMP_FILES)
SRC_FILES := $(SRC_FILES:%=%.o)
SRC_OBJECTS = $(SRC_FILES:%=%)

FT_FILES =	bzero \
			memccpy \
			memchr \
			memcmp \
			memcpy \
			memmove \
			memset \
			strchr \
			strlcat \
			strlcpy \
			strlen \
			strnstr \
			strrchr \
			strncmp \
			isalpha \
			isdigit \
			isspace \
			isalnum \
			isinset \
			isascii \
			isprint \
			toupper \
			tolower \
			isupper \
			islower \
			calloc \
			atoi \
			strdup \
			substr \
			strjoin \
			strtrim \
			strsetcount \
			strmapi \
			itoa \
			putchar_fd \
			putstr_fd \
			putendl_fd \
			putnbr_fd
FT_FILES := $(FT_FILES:%=ft_%.o)

VEC_FILES = new \
			with_capacity \
			push \
			last \
			extend \
			pop \
			shrink \
			shrink_to_fit \
			get \
			drop
VEC_FILES := $(VEC_FILES:%=vec_%.o)

all: $(NAME)

$(NAME): $(SRC_FILES:%=$(OBJ_DIR)%)
	$(MAKE)	-C $(FT_DIR)
	$(MAKE) -C $(MLX_DIR) && cp -P $(MLX_DIR)/libmlx.dylib . \
	&& $(CC)	$^ \
			-Llibft -lft \
			-Lminilibx -lmlx \
			-o $(NAME) \
			$(FLAGS_RELEASE) $(CONFIG_FLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p	$(OBJ_DIR) \
				$(OBJ_DIR)/vec3 \
				$(OBJ_DIR)/mat4 \
				$(OBJ_DIR)/parser \
				$(OBJ_DIR)/string \
				$(OBJ_DIR)/scene \
				$(OBJ_DIR)/vector \
				$(OBJ_DIR)/interaction \
				$(OBJ_DIR)/bmp \
				$(OBJ_DIR)/misc
	$(CC)	-I $(INCLUDE_DIR) \
			-I $(FT_INCLUDE_DIR) \
			-I $(MLX_DIR) \
			-c $^ \
			-o $@ \
			$(FLAGS_RELEASE) $(CONFIG_FLAGS)
clean:
	rm -rf	$(SRC_OBJECTS) $(OBJ_DIR) bonus
	$(MAKE) -C $(FT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf	$(NAME) libmlx.dylib
	$(MAKE) -C $(FT_DIR) fclean

re: fclean
	$(MAKE)

bonus: CONFIG_FLAGS = -D IS_BONUS=1 -D THREAD_COUNT=12
bonus: all

rb:
	rm -rf	$(NAME)
	rm -rf	$(SRC_OBJECTS) $(OBJ_DIR)
	$(MAKE)

rbb:
	rm -rf $(NAME)
	rm -rf $(SRC_OBJETS) $(OBJ_DIR)
	$(MAKE) bonus

rel:
	$(CC)	$(SRC_FILES:%.o=$(SRC_DIR)/%.c) \
			-I $(INCLUDE_DIR) \
			-I $(FT_INCLUDE_DIR) \
			-I $(MLX_DIR) \
			-Llibft -lft \
			-Lminilibx -lmlx \
			$(FLAGS_RELEASE)
