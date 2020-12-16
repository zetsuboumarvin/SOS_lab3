#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int buffer = 0;

static void*	consumer()
{
	while (1)
	{
		--buffer;
		pthread_testcancel();
	}

}

static void*	producer()
{
	while (1)
	{
		++buffer;
		pthread_testcancel();
	}
}


int				main(int argc, char** argv)
{
	pthread_t thread1;
	pthread_t thread2;

	pthread_create(&thread1, NULL, producer, NULL);
	pthread_create(&thread2, NULL, consumer, NULL);
	sleep(3);
	pthread_cancel(thread1);
	pthread_cancel(thread2);
	printf("Buffer = %d\n", buffer);
	return 0;
}
