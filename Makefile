tabuleiro.o: tabuleiro.c
	gcc -o tabuleiro.o -c tabuleiro.c

main : main.o tabuleiro.o
	gcc -o main *.o

all : main

run : main
	./main
