#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h"

int main(){
	LQueue *p=(LQueue *)malloc(sizeof(LQueue));
	int flag=0;
	int data; 
	while(TRUE){
		system("cls");
		meau();
		printf("��������Ҫѡ��ķ���\n");
		switch(input()){
			case 1:{
				InitLQueue(p);
				printf("��ʼ���ɹ�\n");
				flag=1;
				break;
			}
			case 2:{
				if(flag){
					IsEmptyLQueue(p);
				}
				else{
					printf("���ȴ�������\n");
				}
				break;
			}
			case 3:{
				if(flag){
					printf("�������������\n");
					scanf("%d",&data);
					EnLQueue(p,&data);
				}
				else{
					printf("���޶���\n");
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
					GetHeadLQueue(p,&data);
				}
				break;
			}
			case 6:{
				if(flag){
					LengthLQueue(p);
				}
				else{
					printf("���޶���\n");
				}
				break;
			}
			case 7:{
				if(flag){
				TraverseLQueue(p,LPrint);   /* ��������  */
				}
				break;
			}
			case 8:{
				if(flag){
					ClearLQueue(p);
				}
				else{
					printf("���޶���\n");
				}
				break;
			}
			case 9:{
				if(flag){
					DestoryLQueue(p);
				}
				else{
					printf("���޶���\n");
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
	
}
