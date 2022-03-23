#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

/* 主函数的入口 */
int main(){
	int num;
	int flag=0;
	LinkedList head=NULL;
	LinkedList temp=NULL;
	while(SUCCESS){
		system("cls");
		meau();
		switch(enter()){
			case 1 :{
				InitList(&head);
				InitInfo(&head);
				flag=1;
				break;
			}
			case 2 :{
				if(flag){
					if(temp){
						InitList(&temp);
					}
					InsertList(head,temp); 
				}
				else{
					printf("no link for your insert\n");
				}
				break;
			}
			case 3 :{
				if(flag){
					TraverseList(head,visit);   /* 遍历链表 */ 
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 4 :{
				if(flag){
					ReverseList(&head);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 5 :{
				if(flag){
					temp=FindMidNode(&head);
					printf("The mid node's info is'%d\n",temp->data);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 6 :{
				if(flag){
					IsLoopList(head);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 7 :{
				if(flag){
					DeleteList(head,&num);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 8 :{
				if(flag){
					head=ReverseEvenList(&head);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			case 9:{
				if(flag){
					int n;
					printf("enter the num you want to search\n");
					scanf("%d",&n);
					SearchList(head,n);
				}
				else{
					printf("no such link fro your command\n");
				}
				break;
			}
			case 0:{
				if(flag){
					DestroyList(&head);
				}
				else{
					printf("no link for your command\n");
				}
				break;
			}
			default: break;
		}
		system("pause");
	}
}
