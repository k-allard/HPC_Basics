NAME = memoryManipulation

SRCS = *.cpp

OBJS = $(SRCS:.cpp=.o)

CC = /usr/local/opt/llvm/bin/clang++

OPTIONS = -fopenmp -L/usr/local/opt/llvm/lib -I/usr/local/opt/llvm/include

all: $(NAME)

$(NAME):
	@$(CC) -o $(NAME) $(SRCS) $(OPTIONS)
	@echo "\x1b[32m $(NAME) is ready!\x1b[0m"

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re