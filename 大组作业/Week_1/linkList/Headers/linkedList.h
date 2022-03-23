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
Status InitList(LinkedList *L){                  /* 初始化完成 */ 
	(*L)=(LinkedList)malloc(sizeof(LNode));
	if(!(*L)){
		return ERROR;
	}
	(*L)->next=NULL;  
}

Status InitInfo(LinkedList *L){                  /* 信息的创建 */ 
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
	LinkedList p;                                     /* 完成 */ 
	p = (*L)->next;  /* 让指针p指向头指针 */
	while(p){      /* 让另一个指针指向头结点*/
		p = p->next;   /* 然后让p到下一个位置,释放s的内存 */ 
		free(*L);
		*L = p;
	}
	(*L)->next = NULL;    /* 最后让头指针为空 */ 
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
	f = p->next;   /* 找到第一个结点的位置  */
	printf("请输入你要插入位置的前一个的数据\n");
	scanf("%d",&num);   /* 将数据存储到所需要插入的结点当中 */ 
	while(f&&f->data!=num){
		f=f->next;      /* 找到插入位置的前位置 */ 
	}
	if(!f){
		printf("找不到你所要插入的位置结点\n"); 
	} 	  /* 如果指向末尾则返回错误找不到所要插入的前一个位置 */ 
	else{
		printf("请输入你要插入的数据\n");
		scanf("%d",&q->data); 
		q->next = f->next;   /* 插入的操作 */ 
		f->next=q;
		printf("插入成功\n");
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
	m=p->next;  /*第一个结点*/ 
	int num; /* 存储要删的数据*/
	printf("请输入你要删除的数据的前一个数据\n");
	scanf("%d",&num);
	while(m->next&&m->data!=num){   /* 如果能找到前一个位置 那么m->next不为空 从而确保可以删除 */ 
		m=m->next;    /* 遍历找到前一个点的位置 */
	}
	if(!m){
		printf("没有找到所要删除的数据的位置\n") ;
	}
	else{
		q=m->next; /* 使得能找到删除结点的位置*/
		m->next=q->next;   /* 连接后面的结点 */
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
void TraverseList(LinkedList L, void (*visit)(ElemType e)){  /* 遍历链表 */ 
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
		printf("链表可能不存在或者没有存放信息");
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
		printf("这个数据在链表当中\n");
	}
}
/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L){   /* 反转链表 */ 
	if(NULL==L){
		printf("链表不存在无法反转\n");
		return ERROR;
	}
	LinkedList m,q,p;
	m = (*L)->next;   /* 让m到第一个节点的位置*/ 
	(*L)->next=NULL;
	q=p=NULL;  
	while(m){
		q=m->next;   /* 让第一个节点暂时作为一个头结点*/ 
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
		printf("链表不存在\n");
		return ERROR;
	}
	LinkedList p,q;
	q=L;             /* as the slow one */ 
	p=L->next;      /* as the fast one */
	while(1){
		if(!p||!p->next){
			printf("这不是一个循环链表\n");
			return SUCCESS;
		}
		else if(p==q||p->next==q){
			printf("这是一个循环链表\n");
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
		printf("链表可能不存在\n");
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
/* 定义一个菜单函数 */
void meau(void){
	printf("              ************************系统菜单界面***********************\n");
	printf("               ----------------------------------------------------------\n");
	printf("                  **************************************************     \n");
	printf("                  *    1.创建新链表       * *     2.插入新结点     *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    3.输出链表         * *     4.将链表反转     *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    5.找到单链表中点   * *     6.判断是否成环   *     \n");
	printf("                  **************************************************     \n");
	printf("                  *    7.删除结点取值     * *     8.奇偶反转       *     \n");
	printf("                  **************************************************     \n");
	printf("                  *                9.查询数据是否在表中            *     \n");
	printf("                  **************************************************     \n");
	printf("                  *                0.删除链表并退出系统            *     \n");
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
