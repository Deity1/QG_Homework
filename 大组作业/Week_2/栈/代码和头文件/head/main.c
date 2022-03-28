#include <stdio.h>
#include <stdlib.h>
#include "../LinkStack/LinkStack.h" 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkStack *p=(LinkStack*)malloc(sizeof(LinkStack));
	int flag =0;
	ElemType number;
	int length;
	while(SUCCESS){
		system("cls");
		meau();  /* 菜单 */ 
		switch(intput()){
			case 1:{
				initLStack(p);
				flag = 1;    /* 判断是否初始化为后面的内容做前提条件 */ 
				break;
			}
			case 2:{
				if(flag){
					isEmptyLStack(p);
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 3:{
				if(flag){
					printf("请输入你要传入的数据\n");
					scanf("%d",&number);
					pushLStack(p,number);
					}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 4:{
				if(flag){
					popLStack(p,&number);
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 5:{
				if(flag){
					getTopLStack(p,&number);
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 6:{
				if(flag){
					clearLStack(p);
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 7:{
				if(flag){
					LStackLength(p,&length); 
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 8:{
				if(flag){
					destroyLStack(p);
				}
				else{
					printf("栈链还未生成\n");
				}
				break;
			}
			case 0:exit(0);break;
			default: break; 
		}
		system("pause");
	}
	return 0;
}
