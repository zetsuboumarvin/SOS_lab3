#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void*	record_one()
{
	FILE *fin;

	fin = fopen("/home/zetsu/lab3/case1/test_file.txt", "a");
	for (int i = 0; i < 1000; i++)
		fprintf(fin, "Record number ONE\n");
	fclose(fin);
}

static void*	record_two()
{
	FILE *fin;

	fin = fopen("/home/zetsu/lab3/case1/test_file.txt", "a");
	for (int i = 0; i < 1000; i++)
		fprintf(fin, "And this is record number TWO\n");
	fclose(fin);
}

int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, record_one, NULL);
	pthread_create(&thread2, NULL, record_two, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
