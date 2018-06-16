#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *funcao(void *argumentos) {
	printf("\nOLÁ\n");
	return (NULL);
}

int main() {
	pthread_t threads[NUM_THREADS];
	int i;

	for (i = 0; i < NUM_THREADS; ++i) pthread_create(&threads[i], NULL, funcao, NULL);
	printf("Thread principal a esperar a terminação das threads criadas\n");
	for (i = 0; i < NUM_THREADS; ++i) pthread_join(threads[i], NULL);

	return 0;
}