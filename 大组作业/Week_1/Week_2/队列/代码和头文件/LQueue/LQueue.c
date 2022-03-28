#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h" 
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;    /* ��Ϊ������β�巨��ʵ�ֵģ����Գ�ʼ����ʱ��ͷҪָ��� */ 
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p,*q;
	p = Q->front;   /* ��ͷ��㴦���г�����һֱ����β�� */ 
	while(p){
		q = p->next;
		free(p); 
		p = q;
	}
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		printf("��������ǿ�\n");
		return TRUE;
	}
	else{
		printf("������в�Ϊ��\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front == Q->rear){
		printf("��������ǿ�\n");
		return FALSE;
	}
	else{
		e = Q->front->next->data;  /* �Ӷ�ͷֱ�ӻ�ȡԪ��ֵ */ 
		LPrint(e);
		return TRUE;}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	printf("%d",Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->front==Q->rear){
		Q->rear->data = Q->front->data=data;    /* ��������ǿյľͽ����ݲ��뵽ͷ�� */ 
	}
	Node *s = (Node *)malloc(sizeof(Node));  /* ����ָ���� */ 
	s->data = data;
	s->next = NULL;
	Q->rear->next = s;    /* βָ�����һ��ָ��s */ 
	Q->rear = s;      /* ��βָ��������һ����㴦 */ 
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *p;
	if(Q->front == Q->rear){
		printf("��������\n");
		return FALSE;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	Q->length--;
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==Q->rear){
		printf("����Ϊ��\n");
		return ;
	}
	Node *p;
	while(Q->front){
		p = Q->front->next;
		Q->front->next = p->next;
		if(Q->rear == p){
			Q->rear = Q->front;
		}
		free(p);
		Q->length--;
		Q->front = Q->front->next;  
	}
	free(Q);
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q, void (*foo)(void *q)){
	if(Q->front == Q->rear){
		printf("��������ǿ�\n");
		return TRUE;
	}
//	LQueue *p=Q;
//	while(p->rear){
//		LPrint(p->front->data);
//		p->rear = p->rear->next;
//	}
	Node *p=Q->front->next;
	while(p!=NULL){
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
void LPrint(void *q){
	printf("%s\n",q);
}

/* �˵����� */ 
void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("*  1.��ʼ������    *  *   2.�ж϶����Ƿ�Ϊ�� *\n");
	printf("**********************************************\n");
	printf("*  3.���          *  *   4.����             *\n");
	printf("**********************************************\n");
	printf("*  5.�鿴��ͷԪ��  *  *   6.ȷ������ĳ���   *\n");
	printf("**********************************************\n");
	printf("*  7.��������      *  *   8.��ն���         *\n");
	printf("**********************************************\n");
	printf("*  9.���ٶ��в��˳�*  *   0.�˳�ϵͳ         *\n");
	printf("**********************************************\n");
	printf("----------------------------------------------\n");
}

/* ���뺯�� */ 
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
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED


