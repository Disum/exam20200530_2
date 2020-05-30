FLAGS = -g -W -Wall -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -fstack-protector-all -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align -Wno-long-long -Wmissing-declarations -O3

all: a.out

a.out: main.o solve.o matrix.o
	gcc $(FLAGS) main.o solve.o matrix.o -o a.out
main.o: main.c
	gcc $(FLAGS) -c main.c -o main.o
solve.o:
	gcc $(FLAGS) -c solve.c -o solve.o
matrix.o:
	gcc $(FLAGS) -c matrix.c -o matrix.o
