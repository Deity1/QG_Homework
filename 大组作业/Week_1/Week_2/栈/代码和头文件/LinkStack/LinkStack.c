#include "LinkStack.h" 
#include <stdio.h>
#include <stdlib.h> 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
//	s = (LinkStack*)malloc(sizeof(LinkStack));
	if(!s){
		return ERROR;
	}
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack *s){
	if(s->top==NULL){
		printf("ջΪ��\n");
		return SUCCESS;
	}
	else{
		printf("ջ��Ϊ��\n");
		return ERROR;
	} 
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if(s->top==NULL){
		printf("ջΪ��\n");
		return ERROR;
	} /* �ж����ջ�Ƿ��ǿ�ջ */ 
	*e = s->top->data;
	printf("ջ����Ԫ����%d\n", *e);
	return SUCCESS;
}

//���ջ
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

//����ջ
Status destroyLStack(LinkStack *s){
	clearLStack(s); 
	free(s);   //����ջ�Լ���free�� 
	exit(0); 
}

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if(s->top==NULL){
		printf("ջ���ĳ���Ϊ0\n");
		return ERROR;
	}
	LinkStack *p = s;
	while(p->top->next){
		p->top=p->top->next;
	}
	*length = p->count;
	printf("ջ�ĳ���Ϊ%d\n",*length);
	return SUCCESS; 
	
}

//��ջ
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

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	LinkStackPtr p;
	if(s->top==NULL){
		return ERROR;
	} 
	*data = s->top->data;
	p = s->top;  /* ��ջ���Ľ�㸳ֵ��p */
	s->top=s->top->next;
	free(p);  /* �ͷſռ� */
	s->count--;
	return SUCCESS; 
}

void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("*  1.��ʼ��ջ      *  *   2.�ж�ջ�Ƿ�Ϊ��   *\n");
	printf("**********************************************\n");
	printf("*  3.��ջ          *  *   4.��ջ             *\n");
	printf("**********************************************\n");
	printf("*  5.�õ�ջ��Ԫ��  *  *   6.���ջ           *\n");
	printf("**********************************************\n");
	printf("*  7.���ջ����    *  *   8.����ջ���˳�     *\n");
	printf("**********************************************\n");
	printf("*                0.�˳�ϵͳ                  *\n");
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
			printf("��������\n");
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
					printf("������Χ��\n");
					status = 0;
				}
			}
		}
	}while(status == 0);
	return num;
}
