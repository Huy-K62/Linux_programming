.PHONY := all clean

all:
	gcc -o test_process test_process.c -Werror -Wall
	gcc -o zombie_process zombie_process.c -Werror -Wall

clean:
	rm -rf test_process zombie_process
