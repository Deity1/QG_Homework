#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"   

int main(){
	LinkStack *p=NULL;
	int flag =0;
	ElemType number;
	int length;
	while(SUCCESS){
		system("cls");
		meau();  /* �˵� */ 
		switch(intput()){
			case 1:{
				SinitLStack(p);
				flag = 1;    /* �ж��Ƿ��ʼ��Ϊ�����������ǰ������ */ 
				break;
			}
			case 2:{
				if(flag){
					isEmptyLStack(p);
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 3:{
				if(flag){
					printf("��������Ҫ���������\n");
					scanf("%d",&number);
					pushLStack(p,number);
					}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 4:{
				if(flag){
					popLStack(p,&number);
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 5:{
				if(flag){
					getTopLStack(p,&number);
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 6:{
				if(flag){
					clearLStack(p);
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 7:{
				if(flag){
					LStackLength(p,&length); 
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
			case 8:{
				if(flag){
					destroyLStack(p);
				}
				else{
					printf("ջ����δ����\n");
				}
				break;
			}
		}
		system("pause");
	}
} 
