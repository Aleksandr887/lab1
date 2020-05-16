.PHONY: all

all: circle

build/func.o: src/func.c src/func.h
	gcc -Wall -lm -Werror -c src/func.c -o build/func.o

build/main.o: src/func.h src/main.c
	gcc -Wall -lm -Werror -c src/main.c -o build/main.o

circle: build/main.o build/func.o
	gcc -Wall -lm -Werror build/main.o build/func.o -o circle

clean:
	rm -rf circle *.o
