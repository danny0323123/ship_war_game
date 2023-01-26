#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sub.h"

void wait_10sec(){
	printf("Busna,Klein\n");
	printf("拜託了 幫我稱十秒\n");
	clock_t now=clock();
	printf("準備中...\n");
	int soid=0;
	while(clock()-now<10000){
		if(clock()-now==9000&&soid==0){
			printf("好，可以了\n");
			soid=1;
		}
	}
	printf("----switch----\n");
}
void starbust_stream(){
	printf("看我的\n");
	clock_t now=clock();
	while(clock()-now<1000);
	printf("Klein：那到底是什麼技能啊？\n");
	now=clock();
	while(clock()-now<2000);
	printf("師大巴士都~~~駛到陵墓\n");
	now=clock();
	while(clock()-now<2000);
	printf("嗨亞哭\n");
	now=clock();
	while(clock()-now<2000);
	printf("摸多嗨亞哭\n");
	now=clock();
	while(clock()-now<2000);
}
void congratulations(){
	printf("-----閃腰摸眼的悲鳴----\n");
	clock_t now=clock();
	while(clock()-now<1000);
	printf("----------------------congratulations--------------------\n");
}
