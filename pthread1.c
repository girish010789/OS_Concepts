#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *print (void *ptr);

int main () {
        pthread_t thread1, thread2;
        char *m1 = "Creating thread1";
        char *m2 = "Creating thread2";
        int return1, return2;

        //create two independent threads
        return1 = pthread_create (&thread1, NULL, print, (void*) m1);
        sleep(1);
        return2 = pthread_create (&thread2, NULL, print, (void*) m2);
        pthread_join(thread1, NULL);
        pthread_join(thread2, NULL);

        printf("Thread1 finishes execution\n");
        printf("Thread2 finishes execution\n");
        exit(0);
}

void *print (void *ptr) {
        char *message;
        message = (char *) ptr;
        sleep(1);
        printf("%s\n", message);
        return NULL;
}
