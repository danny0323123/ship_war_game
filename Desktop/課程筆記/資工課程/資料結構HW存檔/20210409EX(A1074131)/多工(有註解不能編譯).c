#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


//thread1
void* child1(void* input) 
{
	int i;
  	char *str = (char*) input; // 取得輸入資料
  	for(i = 0; i<3; i++) 
	{
    	printf("%s\n", str); // 每秒輸出文字
    	sleep(1);
  	}
  	return (void *) strlen(str);
}

//thread2
void* child2(void* in) 
{
	int i;
   	for(i = 0; i<in; i++) 
	{
    	printf("child2\n"); // 每秒輸出文字
    	sleep(1);
  	}
   	return 0;
}


int main() 
{
	int i;

  	pthread_t t; // 宣告 pthread 變數
  	pthread_create(&t, NULL, child1, "Child1"); //啟動子執行緒child1
  	void *r1, *r2;

  	// 主執行緒
	for(i = 0; i<3; i++) 
	{
    	printf("Master1\n"); // 每秒輸出文字
    	sleep(1);
  	}


  	pthread_join(t, &r1); // 等待子執行緒執行完成
  	int *result = (int *) r1;
  	printf("-------Returned %d from Child1------- \n", result);
  	
  	pthread_create(&t, NULL, child2, (void*) result);//啟動子執行緒child1

  	// 主執行緒
	for(i = 0; i<3; i++) 
	{
    	printf("Master2\n"); // 每秒輸出文字
    	sleep(1);
  	}  	

  	pthread_join(t, &r2); // 等待子執行緒執行完成
	  
	system("pause");    	
  	return 0;
}
