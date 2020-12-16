NAME = case2

all: main.o
	gcc -pthread main.o -o case2

main.o: main.c
	gcc -c main.c

sync: main_sync.o
	gcc -pthread main_sync.o -o case2

main_sync.o: main_sync.c
	gcc -c main_sync.c

clean:
	rm -f case2
	rm -f main.o
	rm -f main_sync.o
	rm -f test_file.txt
