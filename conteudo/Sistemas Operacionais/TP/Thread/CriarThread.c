#include <stdio.h>
#include <pthread.h>

void *OLA (void *argumetos) {
	printf("\nOla\n");
	pthread_exit(NULL);
}

int main() {
	pthread_t thread;
	int flag;

	printf("A criar uma nova thread;\n");
	flag = pthread_create(&thread, NULL, OLA, NULL);
	if (flag != 0) printf("Erro na criacao duma nova thread.\n");

	OLA(NULL);
	pthread_exit(NULL);

	return 0;
}