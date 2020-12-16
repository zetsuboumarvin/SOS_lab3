NAME = case1

all: main.o
	gcc -pthread main.o -o case1

main.o: main.c
	gcc -c main.c

sync: main_sync.o
	gcc -pthread main_sync.o -o case1

main_sync.o: main_sync.c
	gcc -c main_sync.c

clean:
	rm -f case1
	rm -f main.o
	rm -f main_sync.o
	rm -f test_file.txt
