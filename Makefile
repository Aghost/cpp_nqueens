NAME := queens.out

CC := g++
CSTD := c++17
FLAGS := -Wall -O3


$(NAME): nqueens.cc
	$(CC) -std=$(CSTD) $(FLAGS) nqueens.cc -o $(NAME)

test: $(NAME)
	./$(NAME) 8

clean:
	rm -f queens.out
