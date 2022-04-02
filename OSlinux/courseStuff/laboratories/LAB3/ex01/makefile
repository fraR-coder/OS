CC = gcc
FLAGS = -Wall -g
OBJ=-o main
NAME= e4.c

mainVet.o: mainVet.c
	$(CC) $(FLAGS) -c mainVet.c 

target: 
	$(CC) $(FLAGS) $(OBJ) mainVet.o

install:
	mkdir bin
	mv main bin
	
clean:
	rm -rf *.o

distclean: clean
	rm -R bin