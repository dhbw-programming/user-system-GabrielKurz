main: main.c
	mkdir -p out
	gcc -Wall -Werror -g *.c .assignment/*.c -o out/main
