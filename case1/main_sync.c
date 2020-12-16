#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

static void*	record_one()
{
	FILE *fin;

	pthread_mutex_lock(&lock);
	fin = fopen("/home/zetsu/lab3/case1/test_file.txt", "a");
	for (int i = 0; i < 1000; i++)
		fprintf(fin, "Record number ONE\n");
	fclose(fin);
	pthread_mutex_unlock(&lock);
}

static void*	record_two()
{
	FILE *fin;

	pthread_mutex_lock(&lock);
	fin = fopen("/home/zetsu/lab3/case1/test_file.txt", "a");
	for (int i = 0; i < 1000; i++)
		fprintf(fin, "And this is record number TWO\n");
	fclose(fin);
	pthread_mutex_unlock(&lock);
}

int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&thread1, NULL, record_one, NULL);
	pthread_create(&thread2, NULL, record_two, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_mutex_destroy(&lock);
	return 0;
}
