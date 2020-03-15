#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
int tickets = 100;
pthread_mutex_t _mutex;
void *rount(void *arg)
{
	while(1){
	pthread_mutex_lock(&_mutex);
	if(tickets>0)
	{
		printf("%p i get a tickets:%d\n",pthread_self(),tickets);
		tickets--;
		pthread_mutex_unlock(&_mutex);
	}else{
		pthread_mutex_unlock(&_mutex);
		break;
	}
	}
}
int main(void)
{
	pthread_t t1,t2,t3,t4;
	pthread_create(&t1,NULL,rount,NULL);
	pthread_create(&t2,NULL,rount,NULL);
	pthread_create(&t3,NULL,rount,NULL);
	pthread_create(&t4,NULL,rount,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);
}
