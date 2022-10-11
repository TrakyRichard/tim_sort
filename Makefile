NAME = tim_sort.a
RM = rm -f
SRCS = src/insertion_sort.c src/merge_sort.c src/tim_sort.c \
		utils/stack_ops.c utils/utils.c

OBJS = $(SRCS:.c=.o)

CC = gcc
flgS = -g


$(NAME) : $(OBJS)
		ar rcs $(NAME) $(OBJS)
		${CC} -g tests/main.c tim_sort.a -o tim_sort


$(OBJS) : %.o : %.c
		$(CC) $(flgS) -c $< -o $@


all : $(NAME)

fclean : clean
		@$(RM) $(NAME)

clean :
		@$(RM) $(OBJS)

re : fclean $(NAME)

.PHONY : all clean fclean re
