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

test: NAME
	./enc_denc test/file1 1 Ceaser
	./enc_denc test/file1.encoded 0 Ceaser
	diff test/file1.enoded.decoded test/file1 && cat diff.txt
	cat test/file1.encoded.decoded
	./enc_denc test/file1 1 Atbash
	./enc_denc test/file1.encoded 0 Atbash
	diff test/file1.enoded.decoded test/file1 && cat diff.txt
	./enc_denc test/file1 1 transporate
	./enc_denc test/file1.encoded 0 transporate
	diff test/file1.enoded.decoded test/file1 && cat diff.txt
	./enc_denc test/file2 1 Ceaser
	./enc_denc test/file2.encoded 0 Ceaser
	diff test/file2.enoded.decoded test/file2 && cat diff.txt
	./enc_denc test/file2 1 Atbash
	./enc_denc test/file2.encoded 0 Atbash
	diff test/file2.enoded.decoded test/file2 && cat diff.txt
	./enc_denc test/file2 1 transporate
	./enc_denc test/file2.encoded 0 transporate
	diff test/file2.enoded.decoded test/file2 && cat diff.txt
	./enc_denc test/file3 1 Ceaser
	./enc_denc test/file3.encoded 0 Ceaser
	diff test/file3.enoded.decoded test/file3 && cat diff.txt
	./enc_denc test/file3 1 Atbash
	./enc_denc test/file3.encoded 0 Atbash
	diff test/file3.enoded.decoded test/file3 && cat diff.txt	
	./enc_denc test/file3 1 transporate
	./enc_denc test/file3.encoded 0 transporate
	diff test/file3.enoded.decoded test/file3 && cat diff.txt
