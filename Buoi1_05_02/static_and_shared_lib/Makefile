.PHONY: all clean static shared link

static:
	gcc -c src/print_hello.c -o obj/print_hello.o -I./inc -Werror -Wall
	gcc -c src/print_huy.c -o obj/print_huy.o -I./inc -Werror -Wall
	gcc -c src/main.c -o obj/main.o -I./inc -Werror -Wall
	ar rcs libs/static/libprinttest.a obj/print_hello.o obj/print_huy.o obj/main.o

shared:
	gcc -c src/print_hello.c -o obj/print_hello.o -I./inc -fPIC -Werror -Wall
	gcc -c src/print_huy.c -o obj/print_huy.o -I./inc -fPIC -Werror -Wall
	gcc -c src/main.c -o obj/main.o -I./inc -fPIC -Werror -Wall
	gcc -shared -fPIC obj/print_hello.o obj/print_huy.o obj/main.o -o libs/shared/libprinttest.so
 
link: 
	gcc obj/main.o -Llibs/static -lprinttest -o bin/test_print -Werror -Wall
  
all: static shared link

clean:
	rm -rf obj/* bin/* libs/static/* libs/shared/* 

  

  
