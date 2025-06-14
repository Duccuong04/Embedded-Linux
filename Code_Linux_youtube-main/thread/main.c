#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>


#define THRESHOLD   5


pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int counter = 0; // critical section <=> global resource


typedef struct {
    char name[30];
    char msg[30];
} thread_args_t;


static void *handle_th1(void *args) 
{
    thread_args_t *thr = (thread_args_t *)args;


    pthread_mutex_lock(&lock);
    printf("Hello %s !\n", thr->name);


    while (counter <= THRESHOLD) {
        counter += 1;
        printf("Counter = %d\n", counter);
        sleep(1);
    }


    pthread_cond_signal(&cond);
    printf("thread1 handler, counter = %d\n", counter);
    pthread_mutex_unlock(&lock);


    pthread_exit(NULL); // exit or return;


}


int main(int argc, char const *argv[])
{
    /* code */
    int ret;
    thread_args_t thr;
    pthread_t thread_id1, thread_id2;


    memset(&thr, 0x0, sizeof(thread_args_t));
    strncpy(thr.name, "ThoNV12", sizeof(thr.name));


    if (ret = pthread_create(&thread_id1, NULL, &handle_th1, &thr)) {
        printf("pthread_create() error number=%d\n", ret);
        return -1;
    }


    pthread_mutex_lock(&lock);
    while (1) {
        // ready in advance when pthread_cond_signal() is called
        pthread_cond_wait(&cond, &lock);
        if(counter == THRESHOLD) {
           printf("Global variable counter = %d.\n", counter);
           break;
        }
    }
    pthread_mutex_unlock(&lock);
    
    // used to block for the end of a thread and release
    pthread_join(thread_id1,NULL); 


    return 0;
}
