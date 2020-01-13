# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: dpattij <dpattij@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/03 20:06:23 by dpattij        #+#    #+#                 #
#    Updated: 2019/11/23 23:50:45 by dpattij       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE_DIR = .
SRC_DIR = .

FLAGS_RELEASE = -Wall -Wextra -Werror -O3

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

BONUS_FILES =	lstnew \
				lstadd_front \
				lstsize \
				lstlast \
				lstadd_back \
				lstdelone \
				lstclear \
				lstiter \
				lstmap
BONUS_FILES := $(BONUS_FILES:%=ft_%_bonus.o)

all: $(NAME)

.PHONY: all

%.o: %.c
	$(CC)	-I	$(INCLUDE_DIR) \
		-c	$^ \
		$(FLAGS_RELEASE)

$(NAME): $(FT_FILES) $(VEC_FILES)
	ar	rcs	$(NAME) \
			$(FT_FILES) \
			$(VEC_FILES)

bonus: $(NAME) $(BONUS_FILES)
	ar rcs	$(NAME) \
			$(FT_FILES) \
			$(BONUS_FILES) \
			$(VEC_FILES)
	touch bonus

clean:
	rm -f	$(FT_FILES) \
			$(BONUS_FILES) \
			$(VEC_FILES)
	rm -f	bonus

fclean: clean
	rm -f	$(NAME)

re: fclean
	$(MAKE)
