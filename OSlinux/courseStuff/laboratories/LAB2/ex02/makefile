CC = gcc
FLAGS = -Wall -g
OBJ=-o main
NAME= main.c

target: 
	gcc -Wall -g -o main main.c

target1:
	$(CC) $(FLAGS) $(OBJ) $(NAME)
install:
	mkdir bin
	mv main bin
	
clean:
	rm -rf *.o

distclean: clean
	rm -R bin