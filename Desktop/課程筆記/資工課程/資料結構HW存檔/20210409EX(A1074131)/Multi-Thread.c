#include <stdio.h>
#include <pthread.h>
#include <unistd.h>



void* child1(void* input) 
{
	int i;
  	char *str = (char*) input; 
  	for(i = 0; i<3; i++) 
	{
    	printf("%s\n", str); 
    	sleep(1);
  	}
  	return (void *) strlen(str);
}


void* child2(void* in) 
{
	int i;
   	for(i = 0; i<in; i++) 
	{
    	printf("child2\n"); 
    	sleep(1);
  	}
   	return 0;
}


int main() 
{
	int i;

  	pthread_t t; 
  	pthread_create(&t, NULL, child1, "Child1");
  	void *r1, *r2;

	for(i = 0; i<3; i++) 
	{
    	printf("Master1\n"); 
    	sleep(1);
  	}


  	pthread_join(t, &r1); 
  	int *result = (int *) r1;
  	printf("-------Returned %d from Child1------- \n", result);
  	
  	pthread_create(&t, NULL, child2, (void*) result);

	for(i = 0; i<3; i++) 
	{
    	printf("Master2\n"); 
    	sleep(1);
  	}  	

  	pthread_join(t, &r2); 
	  
	system("pause");    	
  	return 0;
}
