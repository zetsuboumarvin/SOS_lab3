#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

long common = 0;

static void*	write_common1()
{
	for (int i = 0; i < 100000; i++)
		common++;
}

static void*	write_common2()
{
	for (int i = 0; i < 100000; i++)
		common++;
}


int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, write_common1, NULL);
	pthread_create(&thread2, NULL, write_common2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Common = %ld\n", common);
	return 0;
}
