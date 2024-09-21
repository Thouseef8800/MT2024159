/**
Name:Q7.c
Author:Thouseef
Description:Write a simple program to print the created thread ids.
Date:18th September 2024
**/
#include<stdio.h>
#include<pthread.h>

void *threadfunc(void *arg){
 pthread_t thread_id = pthread_self();
    printf("thread id: %lu\n", (unsigned long)thread_id);
    return NULL;
 return 0;
}
int main(void){
 int i;
 pthread_t  tid[3];
 for(i=0;i<3;i++){
  pthread_create(&tid[i],NULL,threadfunc,NULL);
 }
 for(i=0;i<3;i++){
 pthread_join(tid[i],NULL);
 }
 return 0;
}
/**Output:
thread id: 139773731665600
thread id: 139773723272896
thread id: 139773714880192
**/
