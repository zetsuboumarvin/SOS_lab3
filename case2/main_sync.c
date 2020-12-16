#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

long common = 0;
sem_t sem;

static void*	write_common()
{
	for (int i = 0; i < 100000; i++)
	{
		sem_wait(&sem);
		common++;
		sem_post(&sem);
	}
}


int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	sem_init(&sem, 0, 0);
	sem_post(&sem);
	pthread_create(&thread1, NULL, write_common, NULL);
	pthread_create(&thread2, NULL, write_common, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	printf("Common = %ld\n", common);
	sem_destroy(&sem);
	return 0;
}
