#include <pthread.h>
#include <stdio.h>
void *thread_func(void *arg) {
    printf("Thread running\n");
    return NULL;
}
int main() {
    pthread_t thread;
    int rc;

    rc = pthread_create(&thread, NULL, thread_func, NULL);
    if (rc) {
        printf("Error creating thread: %d\n", rc);
        return 1;
    }

    pthread_join(thread, NULL);

    return 0;
}
