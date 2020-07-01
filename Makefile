tabuleiro.o: tabuleiro.c
	gcc -o tabuleiro.o -c tabuleiro.c

play.o: play.c
	gcc -o play.o -c play.c

main : main.o tabuleiro.o play.o
	gcc -o main *.o

all : main

run : main
	./main
