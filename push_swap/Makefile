NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

HEADER = ${addprefix includes/, push_swap.h}

UTILS = ${addprefix utils/, utils.c free_err.c}

SRC = ${addprefix source/, push_swap.c operations.c op_push.c mini_sort.c \
		mega_sort.c indexer.c} ${UTILS}

OBJS = ${SRC:c=o}

%.o : %.c ${HEADER} Makefile
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${OBJS} ${HEADER} Makefile
	${CC} ${OBJS} -o $@

all : ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : push_swap