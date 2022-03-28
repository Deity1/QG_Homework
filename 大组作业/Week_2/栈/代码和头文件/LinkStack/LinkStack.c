#include "LinkStack.h" 
#include <stdio.h>
#include <stdlib.h> 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
//	s = (LinkStack*)malloc(sizeof(LinkStack));
	if(!s){
		return ERROR;
	}
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("栈为空\n");
		return SUCCESS;
	}
	else{
		printf("栈不为空\n");
		return ERROR;
	} 
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("栈为空\n");
		return ERROR;
	} /* 判断这个栈是否是空栈 */ 
	*e = s->top->data;
	printf("栈顶的元素是%d\n", *e);
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack *s){
	LinkStackPtr p;
	while(s->top){
		p = s->top;
		s->top = s->top->next;
		s->count--;
		free(p);
	}
	return SUCCESS;
	
}

//销毁栈
Status destroyLStack(LinkStack *s){
	clearLStack(s); 
	free(s);   //最后把栈自己给free掉 
	exit(0); 
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if(s->top==NULL){
		printf("栈链的长度为0\n");
		return ERROR;
	}
	LinkStack *p = s;
	while(p->top->next){
		p->top=p->top->next;
	}
	*length = p->count;
	printf("栈的长度为%d\n",*length);
	return SUCCESS; 
	
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	LinkStackPtr p;
//	if(s->top==NULL){
//		s->top->data = data;
//		return SUCCESS;
//	}
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	if(!p){
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	if(s->top==NULL){
		return ERROR;
	} 
	*data = s->top->data;
	p = s->top;  /* 将栈顶的结点赋值给p */
	s->top=s->top->next;
	free(p);  /* 释放空间 */
	s->count--;
	return SUCCESS; 
}

void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("*  1.初始化栈      *  *   2.判断栈是否为空   *\n");
	printf("**********************************************\n");
	printf("*  3.入栈          *  *   4.出栈             *\n");
	printf("**********************************************\n");
	printf("*  5.得到栈顶元素  *  *   6.清空栈           *\n");
	printf("**********************************************\n");
	printf("*  7.检测栈长度    *  *   8.销毁栈并退出     *\n");
	printf("**********************************************\n");
	printf("*                0.退出系统                  *\n");
	printf("**********************************************\n");
	printf("----------------------------------------------\n");
}
int intput(){
	int i;
	int num=0;
	int status=0;
	char s[100];
	do{
		scanf("%s",s);
		status = 1;
		for(i=0;s[i]!='\0';i++){
			if(i==0){
				if(s[i]=='-'||s[i]=='+')continue;
			}
			else{
				if(s[i]<'0'||s[i]>'7'){
					status = 0;
				}
			}
		}
		if(status == 0){
			printf("输入有误\n");
		}
		else{
			for(i=0,num=0;s[i]!='\0';i++){
				if(i==0){
					if(s[i]=='-'||s[i]=='+'){
						continue;
					}
					else{
						num *= 10;
						num += (s[i]-48);
					}
				}
				else{
					num *= 10;
					num += (s[i]-48);
				}
				if(s[0] == '-'){
					num = -num;
				}
				if(i>=7){
					printf("超出范围了\n");
					status = 0;
				}
			}
		}
	}while(status == 0);
	return num;
}
