/***************************************************************************************
 *	File Name				:	duLinkedList.h
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
#include <stdio.h>
#include <stdlib.h>
#ifndef DULINKEDLIST_H_INCLUDED
#define DULINKEDLIST_H_INCLUDED

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
typedef struct DuLNode {
	ElemType data;
  	struct DuLNode *prior,  *next;
} DuLNode, *DuLinkedList;

// define status
typedef enum Status {
	ERROR,
	SUCCESS,
} Status;


/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L){
	(*L) = (DuLinkedList)malloc(sizeof(DuLNode));
	if(!(*L)){
		return ERROR;     /* means can't build a link */
	}
	(*L)->prior=(*L)->next=NULL;
}
Status InitList_Input(DuLinkedList *L){
	DuLinkedList q=*L,p;
	int num,i=1;
	printf("how much node do you want to insert");
	scanf("%d",&num);
	while(i<=num){
		p=(DuLinkedList)malloc(sizeof(DuLNode));
		p->data=i;
		q->next=p;
		p->prior=q;
		q=p;
		p->next=NULL;
		i++;
	}
	printf("the link has been created\n");
	return SUCCESS;
}


/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L){
	DuLinkedList p = (*L)->next;
	while(p){
		p=p->next;
		free(*L);
		(*L)=p;
	}
	exit(0);
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q){
	if(!p){
		printf("can't find the link\n'");
		return ERROR;
	}
	q->prior=p;
	q->next=p->next;
	p->next=q;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q){
	if(!p){
		printf("can't find the node to insert\n'");
		return ERROR;
	}
	p=p->next;
	q->prior=p;
	q->next=p->next;
	p->next=q;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e){
	if(!p||p->next==NULL){
		printf("can't find the node befor p\n");
		return ERROR;
	}
	DuLinkedList q,temp;
	q=p->next; 
	while(q->data!=*e){    
		temp=q; 
		q=q->next;         /* get the element position */
	}
	q->next->prior=temp;   /* get the piror position */
	temp->next=q->next;   /* delete the node of e */
	free(q);             /* free room */
	printf("The node have been removed\n");
	return SUCCESS;
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)){
	DuLinkedList p;
	p=L->next;
	while(p){
		visit(p->data);
		p=p->next;
	}
	printf("NULL\n");
}

void visit(ElemType e){
	printf("%d->",e);
}

void meau(void){
	printf("              ************************系统菜单界面***********************\n");
	printf("               ----------------------------------------------------------\n");
	printf("                  **************************************************     \n");
	printf("                  *    1.创建新链表       * *     2.在结点前插入   *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    3.在结点后面插入   * *     4.删除特定元素   *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    5.删除链表且退出   * *     6.输出整个链表   *     \n");
	printf("                  **************************************************     \n");
	printf("                  *                    7.退出系统                  *     \n");
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
					if(s[i]<'0'||s[i]>'7'){
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
				if(num<0||num>7){
					printf("the input is overlow\n");
					status=ERROR;
				}
			}
		}
	}while(status==ERROR);
	return num;
}
 /**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif
