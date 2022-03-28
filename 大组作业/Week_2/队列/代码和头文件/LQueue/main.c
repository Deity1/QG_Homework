#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int intput(); 
int main(int argc, char *argv[]) {
	LQueue *p=(LQueue *)malloc(sizeof(LQueue));
	int flag=0; 
	while(TRUE){
		system("cls");
		meau();
		printf("请输入你要选择的服务\n");
		switch(intput()){
			case 1:{
				InitLQueue(p);
				printf("初始化成功\n");
				flag=1;
				break;
			}
			case 2:{
				if(flag){
					IsEmptyLQueue(p);
				}
				else{
					printf("请先创建队列\n");
				}
				break;
			}
			case 3:{
				if(flag){
					printf("请输入你的数据\n");
					scanf("%s",datatype);
					EnLQueue(p,(char *)datatype);
				}
				else{
					printf("暂无队列\n");
				}
				break;
			}
			case 4:{
				if(flag){
					DeLQueue(p);
				}
				break;
			}
			case 5:{
				if(flag){
					GetHeadLQueue(p,datatype);
				}
				break;
			}
			case 6:{
				if(flag){
					LengthLQueue(p);
				}
				else{
					printf("暂无队列\n");
				}
				break;
			}
			case 7:{
				if(flag){
				TraverseLQueue(p,LPrint);   /* 遍历队列  */
				}
				break;
			}
			case 8:{
				if(flag){
					ClearLQueue(p);
				}
				else{
					printf("暂无队列\n");
				}
				break;
			}
			case 9:{
				if(flag){
					DestoryLQueue(p);
					exit(0);
				}
				else{
					printf("暂无队列\n");
				}
				break;
			}
			case 0:{
				exit(0);
				break;
			}
		}
		system("pause");
	}
	return 0;
}
