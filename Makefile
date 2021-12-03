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

test: $(NAME)
	./enc_denc testfiles/file1 1 Ceaser
	./enc_denc testfiles/file1.encoded 0 Ceaser
	diff testfiles/file1.encoded.decoded testfiles/file1
	./enc_denc testfiles/file1 1 Atbash
	./enc_denc testfiles/file1.encoded 0 Atbash
	diff testfiles/file1.encoded.decoded testfiles/file1
	./enc_denc testfiles/file1 1 transporate
	./enc_denc testfiles/file1.encoded 0 transporate
	diff testfiles/file1.encoded.decoded testfiles/file1
	./enc_denc testfiles/file2 1 Ceaser
	./enc_denc testfiles/file2.encoded 0 Ceaser
	diff testfiles/file2.encoded.decoded testfiles/file2
	./enc_denc testfiles/file2 1 Atbash
	./enc_denc testfiles/file2.encoded 0 Atbash
	diff testfiles/file2.encoded.decoded testfiles/file2
	./enc_denc testfiles/file2 1 transporate
	./enc_denc testfiles/file2.encoded 0 transporate
	diff testfiles/file2.encoded.decoded testfiles/file2
	./enc_denc testfiles/file3 1 Ceaser
	./enc_denc testfiles/file3.encoded 0 Ceaser
	diff testfiles/file3.encoded.decoded testfiles/file3
	./enc_denc testfiles/file3 1 Atbash
	./enc_denc testfiles/file3.encoded 0 Atbash
	diff testfiles/file3.encoded.decoded testfiles/file3
	./enc_denc testfiles/file3 1 transporate
	./enc_denc testfiles/file3.encoded 0 transporate
	diff testfiles/file3.encoded.decoded testfiles/file3
