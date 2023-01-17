NAME = push_swap

NAME_BONUS = checker

SRCS = 	src/push_swap.c\
		src/ft_strdup.c\
		src/ft_atoi.c\
		src/ft_strlen.c\
		src/ft_split.c\
		src/quick_sort.c\
		src/medianne.c\
		utils/get_instructions.c\
		utils/list_utils.c\
		utils/push_instructions.c\
		utils/reverse_rotate_instructions.c\
		utils/rotate_instructions.c\
		utils/swap_instructions.c\
		algo/algo_large.c\
		algo/algo_utils.c\
		algo/small_sort.c

SRCS_BONUS =	bonus/src/checker.c\
				bonus/src/ft_atoi.c\
				bonus/src/ft_split.c\
				bonus/src/ft_strlen.c\
				bonus/src/ft_strdup.c\
				bonus/src/func.c\
				bonus/src/medianne.c\
				bonus/src/quick_sort.c\
				bonus/utils/list_utils.c\
				bonus/utils/push_instructions.c\
				bonus/utils/reverse_rotate_instructions.c\
				bonus/utils/rotate_instructions.c\
				bonus/utils/swap_instructions.c

INCLUDES = push_swap.h

OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

all: ${NAME}

bonus: ${NAME_BONUS}

$(NAME): ${OBJS}
	${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	${CC} ${CFLAGS} -I checker/checker.h ${OBJS_BONUS} -o ${NAME_BONUS}

clean:
	rm -rf ${OBJS}
	rm -rf ${OBJS_BONUS}

fclean:
	rm -rf ${NAME}
	rm -rf ${OBJS}
	rm -rf ${NAME_BONUS}
	rm -rf ${OBJS_BONUS}

re:	fclean all

.PHONY: all bonus clean fclean re