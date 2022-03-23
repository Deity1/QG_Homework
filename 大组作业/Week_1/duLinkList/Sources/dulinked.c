#include<stdio.h>
#include<stdlib.h>
#include "duLinkedList.h"

int main(){
	DuLinkedList head;    /* 声明一个链表的指针用于调用函数 */ 
	DuLinkedList temp;   /* 作为一个插入的结点 */ 
	int flag=0;
	while(SUCCESS){
		system("cls");
		meau();		
		switch(enter()){
			case 1:{
				InitList_DuL(&head);
				InitList_Input(&head);
				flag=1;
				break;
			}
			case 2:{
				if(flag){
				if(temp!=NULL){
					InitList_DuL(&temp);
				}
				printf("请输入你要插入的结点数据\n");
				scanf("%d",&temp->data);
				InsertBeforeList_DuL(head,temp);}
				else{
					printf("no link for your command\n");
				}
				break;}
			case 3:{
				if(flag){
				if(temp!=NULL){
					InitList_DuL(&temp);
				}
				printf("the info you want to insert\n");
				scanf("%d",&temp->data);
				InsertAfterList_DuL(head,temp);}
				else{
					printf("no such link for you command\n");
				}
				break;
			}
			case 4:{
				if(flag){
				int number;
				printf("please enter the number you want to delete\n");
				scanf("%d",&number);
				DeleteList_DuL(head,&number);}
				else{
					printf("no such link for your command\n");
				}
				break;
			}
			case 5:{
				if(flag){
				DestroyList_DuL(&head);}
				else{
					printf("no such link\n");
				}
				break;
			}
			case 6:TraverseList_DuL(head,visit);break;
			case 7:exit(0);break;
			default :break;
		} 	
		system("pause");
	}
}
