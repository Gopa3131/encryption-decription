SRCS = $(wildcard *.cpp) $(wildcard ./Ceaser/*.cpp) $(wildcard ./AtBash/*.cpp) $(wildcard ./Transporation/*.cpp) $(wildcard ./RSA/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CC = g++

FLAGS = -g -fmax-errors=5

NAME = enc_denc

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $^ -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

