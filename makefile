NAME := libasm.a

SRC :=	ft_strlen.s ft_write.s ft_read.s ft_strcpy.s ft_strcmp.s ft_strdup.s

OBJ := $(SRC:.s=.o)

CC := gcc

NASM := nasm -fmacho64 -g

FLAGS = -Wall -Wextra -Werror

HEADER = libasm.h

all: $(NAME)
$(NAME): $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ) $?

%.o:%.s
	$(NASM) -I. -s $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean all

test1: all
	$(CC) $(FLAGS) -L. -lasm test.c

test2: all
	$(CC) $(FLAGS) -L. -lasm main.c

link:
	ld -macosx_version_min 10.7.0 -lSystem -o $(NAME) -no_pie $(OBJ)

add:
	git add $(SRC) libasm.h test.c makefile