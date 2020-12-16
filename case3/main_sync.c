#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mtx;
pthread_cond_t cond;
int buffer = 0;

static void*	consumer()
{
	while (1)
	{
		pthread_mutex_lock(&mtx);
		while (buffer <= 0)
			pthread_cond_wait(&cond, &mtx);
		--buffer;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mtx);
		pthread_testcancel();
	}

}

static void*	producer()
{
	while (1)
	{
		pthread_mutex_lock(&mtx);
		while (buffer > 0)
			pthread_cond_wait(&cond, &mtx);
		++buffer;
		pthread_cond_signal(&cond);
		pthread_mutex_unlock(&mtx);
		pthread_testcancel();
	}
}


int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_mutex_init(&mtx, 0);
	pthread_create(&thread1, NULL, producer, NULL);
	pthread_create(&thread2, NULL, consumer, NULL);
	sleep(3);
	pthread_cancel(thread1);
	pthread_cancel(thread2);
	printf("Buffer = %d\n", buffer);
	pthread_mutex_destroy(&mtx);
	return 0;
}
