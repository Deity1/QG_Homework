#include <stdio.h>
#include <stdlib.h>
#include "../head/LQueue.h" 
/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q){
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	Q->front->next = NULL;    /* 因为队列是尾插法来实现的，所以初始化的时候头要指向空 */ 
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q){
	Node *p,*q;
	p = Q->front;   /* 在头结点处进行出队列一直到队尾处 */ 
	while(p){
		q = p->next;
		free(p); 
		p = q;
	}
	Q->front = Q->rear = NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q){
	if(Q->front == Q->rear){
		printf("这个队列是空\n");
		return TRUE;
	}
	else{
		printf("这个队列不为空\n");
		return FALSE;
	}
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e){
	if(Q->front == Q->rear){
		printf("这个队列是空\n");
		return FALSE;
	}
	else{
		e = Q->front->next->data;  /* 从队头直接获取元素值 */ 
		LPrint(e);
		return TRUE;}
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q){
	printf("%d",Q->length);
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data){
	if(Q->front==Q->rear){
		Q->rear->data = Q->front->data=data;    /* 如果队列是空的就将数据插入到头处 */ 
	}
	Node *s = (Node *)malloc(sizeof(Node));  /* 开辟指针域 */ 
	s->data = data;
	s->next = NULL;
	Q->rear->next = s;    /* 尾指针的下一个指向s */ 
	Q->rear = s;      /* 将尾指针移向下一个结点处 */ 
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q){
	Node *p;
	if(Q->front == Q->rear){
		printf("暂无数据\n");
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q){
	if(Q->front==Q->rear){
		printf("队列为空\n");
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(LQueue *Q, void (*foo)(void *q)){
	if(Q->front == Q->rear){
		printf("这个队列是空\n");
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
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q){
	printf("%s\n",q);
}

/* 菜单函数 */ 
void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("*  1.初始化队列    *  *   2.判断队列是否为空 *\n");
	printf("**********************************************\n");
	printf("*  3.入队          *  *   4.出队             *\n");
	printf("**********************************************\n");
	printf("*  5.查看队头元素  *  *   6.确定队伍的长度   *\n");
	printf("**********************************************\n");
	printf("*  7.遍历队列      *  *   8.清空队列         *\n");
	printf("**********************************************\n");
	printf("*  9.销毁队列并退出*  *   0.退出系统         *\n");
	printf("**********************************************\n");
	printf("----------------------------------------------\n");
}

/* 输入函数 */ 
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
/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
//#endif // LQUEUE_H_INCLUDED


