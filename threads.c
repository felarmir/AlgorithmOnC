#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

static void thread_wait(void) {
	time_t start = time(NULL);
	while(time(NULL) == start)
		;
}

static void *func_printer(void *args) {
	for (int i = 0; i < 20; ++i) {
		printf("b\n");
		thread_wait();
	}
	return NULL;
}

int main(int argc, char const *argv[]) {
	pthread_t thread;
	if (pthread_create(&thread, NULL, func_printer, NULL)) {
		return EXIT_FAILURE;
	}
	
	for (int i = 0; i < 20; ++i) {
		printf("a\n");
		thread_wait();
	}

	if (pthread_join(thread, NULL)) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}