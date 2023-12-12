#include<iostream>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

#define THREAD_NUM 4

sem_t semaphore;

void* routine(void* args) 
{
    sem_wait(&semaphore);
    sleep(1);
    cout<<"Hello from thread "<< *(int*)args<<endl;
    sem_post(&semaphore);
    delete(args);
}

int main(int argc, char *argv[]) 
{
    pthread_t th[THREAD_NUM];
    sem_init(&semaphore, 0, 4);
    int i;
    for (i = 0; i < THREAD_NUM; i++) 
    {
        int* a = new int;
        *a = i;
        if (pthread_create(&th[i], NULL, &routine, a) != 0) 
        {
            perror("Failed to create thread");
        }
    }

    for (i = 0; i < THREAD_NUM; i++) 
    {
        if (pthread_join(th[i], NULL) != 0) 
        {
            perror("Failed to join thread");
        }
    }
    sem_destroy(&semaphore);
    return 0;
}