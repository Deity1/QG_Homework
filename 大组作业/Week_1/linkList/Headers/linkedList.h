/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2020 QG Studio
 *	SYSTEM					:   win10
 *	Create Data				:	2020.3.28
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

/**************************************************************
*	Macro Define Section
**************************************************************/

#define OVERFLOW -1

/**************************************************************
*	Struct Define Section
**************************************************************/

// define element type
typedef int ElemType;

// define struct of linked list
typedef struct LNode {
	ElemType data;
  	struct LNode *next;
} LNode, *LinkedList;

// define Status
typedef enum Status {
	ERROR,
	SUCCESS
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */    
Status InitList(LinkedList *L){                  /* ��ʼ����� */ 
	(*L)=(LinkedList)malloc(sizeof(LNode));
	if(!(*L)){
		return ERROR;
	}
	(*L)->next=NULL;  
}

Status InitInfo(LinkedList *L){                  /* ��Ϣ�Ĵ��� */ 
	LinkedList q=*L,p;
	int num,i=1,info;
	printf("how much node do you want to insert\n");
	scanf("%d",&num);
	while(i<=num){
		p=(LinkedList)malloc(sizeof(LNode));
		printf("please enter the %d node's info\n",i);
		scanf("%d",&info);
		p->data=info;
		q->next=p;      /* BUG */
		q=p;
		p->next=NULL;
		i++;
	}
	q->next=NULL;
	printf("the link has been created\n");
	return SUCCESS;
}
/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L){
	LinkedList p;                                     /* ��� */ 
	p = (*L)->next;  /* ��ָ��pָ��ͷָ�� */
	while(p){      /* ����һ��ָ��ָ��ͷ���*/
		p = p->next;   /* Ȼ����p����һ��λ��,�ͷ�s���ڴ� */ 
		free(*L);
		*L = p;
	}
	(*L)->next = NULL;    /* �����ͷָ��Ϊ�� */ 
	exit(0); 
}
/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */ 
Status InsertList(LNode *p, LNode *q){
	int num;
	if(p==NULL){
		printf("no such a link\n");
		return ERROR;
	}
	LinkedList f=p;		
	f = p->next;   /* �ҵ���һ������λ��  */
	printf("��������Ҫ����λ�õ�ǰһ��������\n");
	scanf("%d",&num);   /* �����ݴ洢������Ҫ����Ľ�㵱�� */ 
	while(f&&f->data!=num){
		f=f->next;      /* �ҵ�����λ�õ�ǰλ�� */ 
	}
	if(!f){
		printf("�Ҳ�������Ҫ�����λ�ý��\n"); 
	} 	  /* ���ָ��ĩβ�򷵻ش����Ҳ�����Ҫ�����ǰһ��λ�� */ 
	else{
		printf("��������Ҫ���������\n");
		scanf("%d",&q->data); 
		q->next = f->next;   /* ����Ĳ��� */ 
		f->next=q;
		printf("����ɹ�\n");
		return SUCCESS;
	}		
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e){
	LinkedList m,q;
	m=p->next;  /*��һ�����*/ 
	int num; /* �洢Ҫɾ������*/
	printf("��������Ҫɾ�������ݵ�ǰһ������\n");
	scanf("%d",&num);
	while(m->next&&m->data!=num){   /* ������ҵ�ǰһ��λ�� ��ôm->next��Ϊ�� �Ӷ�ȷ������ɾ�� */ 
		m=m->next;    /* �����ҵ�ǰһ�����λ�� */
	}
	if(!m){
		printf("û���ҵ���Ҫɾ�������ݵ�λ��\n") ;
	}
	else{
		q=m->next; /* ʹ�����ҵ�ɾ������λ��*/
		m->next=q->next;   /* ���Ӻ���Ľ�� */
		*e=q->data;
		free(q);
	}
}
/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)){  /* �������� */ 
	LinkedList m;
	m=L->next;
	while(m){
		visit(m->data);    /*use a function to show the info */
		m=m->next;
	}
	printf("NULL\n");
}
void visit(ElemType e){
	printf("%d->", e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e){
	if(NULL==L||L->next==NULL){
		printf("������ܲ����ڻ���û�д����Ϣ");
	}
	LinkedList p;
	p=L->next;
	while(p&&p->data!=e){
		p=p->next;
	}
	if(!p){
		return ERROR;
	}
	else{
		printf("���������������\n");
	}
}
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L){   /* ��ת���� */ 
	if(NULL==L){
		printf("���������޷���ת\n");
		return ERROR;
	}
	LinkedList m,q,p;
	m = (*L)->next;   /* ��m����һ���ڵ��λ��*/ 
	(*L)->next=NULL;
	q=p=NULL;  
	while(m){
		q=m->next;   /* �õ�һ���ڵ���ʱ��Ϊһ��ͷ���*/ 
		m->next=p;        
		p=m;
		m=q;
	}
	(*L)->next=p;
	return SUCCESS;
}
/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L){
	if(NULL==L||L->next==NULL){
		printf("��������\n");
		return ERROR;
	}
	LinkedList p,q;
	q=L;             /* as the slow one */ 
	p=L->next;      /* as the fast one */
	while(1){
		if(!p||!p->next){
			printf("�ⲻ��һ��ѭ������\n");
			return SUCCESS;
		}
		else if(p==q||p->next==q){
			printf("����һ��ѭ������\n");
		}
		else{
			q=q->next;
			p=p->next->next;   
		}
	}
	
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L){
	LinkedList first=(*L)->next;
	LinkedList temp;
	LinkedList head=(LinkedList)malloc(sizeof(LNode));
	head->next=NULL;
	LinkedList fun=head;
	while(first&&first->next){
		temp=first;  /* store the info for the subsequent change */
		fun->next=temp->next;
		fun=fun->next;
		first=first->next->next;
		fun->next=temp;
		fun=fun->next;
	}
	fun->next=first;
	return head;
	
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L){   /* for the fast to move to the end, the slow one move to the mid */
	if((*L)==NULL||(*L)->next==NULL){
		printf("������ܲ�����\n");
		return (*L);
	}
	LinkedList fast,slow;
	fast=slow=(*L);
	while(fast){
		if(fast->next==NULL){
			fast = fast->next;
		}
		else{
			fast = fast->next->next;
		}
		slow = slow->next;
	}
	return slow;
}

 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
/* ����һ���˵����� */
void meau(void){
	printf("              ************************ϵͳ�˵�����***********************\n");
	printf("               ----------------------------------------------------------\n");
	printf("                  **************************************************     \n");
	printf("                  *    1.����������       * *     2.�����½��     *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    3.�������         * *     4.������ת     *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    5.�ҵ��������е�   * *     6.�ж��Ƿ�ɻ�   *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    7.ɾ�����ȡֵ     * *     8.��ż��ת       *     \n");
	printf("                  **************************************************     \n");
	printf("                  *                9.��ѯ�����Ƿ��ڱ���            *     \n");
	printf("                  **************************************************     \n");
	printf("                  *                0.ɾ�������˳�ϵͳ            *     \n");
	printf("                  **************************************************     \n");
	printf("               ----------------------------------------------------------\n");
}

int enter(){
	int num;
	int i;
	int status;
	char s[100];   /* prevent the user input illegal info*/
	do{
		scanf("%s",s);
		status =SUCCESS;
		for(i=0;s[i]!='\0';i++){
			if(i==0){
				if(s[i]=='-'||s[i]=='+')continue;  /* distribute the '+''-' */
				else{
					if(s[i]<'0'||s[i]>'9'){
						status = ERROR;
					}
				}
			}
			if(status==ERROR){
				printf("no this choice \n");
			}
			else{
				for(i=0;s[i]!='\0';i++){
					if(s[i]=='-'||s[i]=='+'){
						continue;
					}
					else{
						num*=10;
						num+=s[i]-48;
					}
				}
				if(s[0]=='-'){
					num=-num;
				}
				if(num<0||num>9){
					printf("the input is overlow\n");
					status=ERROR;
				}
			}
		}
	}while(status==ERROR);
	return num;
}
