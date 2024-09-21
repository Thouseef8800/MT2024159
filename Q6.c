/**
Name:Q6.c
Author:Thouseef
Description:Write a simple program to create three threads.
Date:18th September 2024
**/
#include<stdio.h>
#include<pthread.h>

void *threadfunc(void *arg){
 printf("Thread created\n");
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
Thread created
Thread created
Thread created
**/
