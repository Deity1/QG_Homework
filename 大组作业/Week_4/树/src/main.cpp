#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*Rchild;
}BiTNode;

	BiTNode *
	T ;

//创建二叉排序树 
BiTNode *CreateTree(BiTNode* T,int data){
	if(T==NULL){
		T = (BiTNode*)malloc(sizeof(BiTNode));
		T->data = data;
		T->lchild=NULL;
		T->Rchild=NULL;
		return T;
	}
	if(data < T->data){
		T->lchild = CreateTree(T->lchild,data);
	}else if(data > T->data){
		T->Rchild = CreateTree(T->Rchild,data);
	}else{
		printf("该元素已经在树中\n");
	}
	return T;
}

//遍历二叉树（先序遍历）
void PreOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	printf("%d\t",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->Rchild);
} 

//遍历二叉树（中序遍历）
void InOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%d\t",T->data);
	InOrderTraverse(T->Rchild);
} 

//遍历二叉树（后序遍历）
void PostOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	InOrderTraverse(T->lchild);
	InOrderTraverse(T->Rchild);
	printf("%d\t",T->data);
} 

//查找树 
BiTNode *searchTree(BiTNode *T,int n){	
	BiTNode *p = T;
	if(p->data == n){
		return p;
	}else if(n < (p->data)){
		if(p->lchild==NULL){
			return NULL;
		}
		else{
			p=p->lchild;
			searchTree(p,n);
		}
	}else if(n > (p->data)){
		
		if(p->Rchild==NULL){
			return NULL;
		}
		else{
			p=p->Rchild;
			searchTree(p,n);
		}
	}
		
}


//删除结点
BiTNode *DeleteTreeNode(BiTNode *T,int n){
	if(T==NULL){
		return NULL;
	}
	BiTNode *p = NULL;
	BiTNode *fp = NULL;
	p = T;
	
	while(1){//寻找要删除的位置 
		fp = p;
		if(p->data > n){
			p = p->lchild;
		}else if( p ->data < n){
			p = p->Rchild;
		}
		if(p->data ==n){
			break;
		}
	}
	if(p==NULL){
		return T;
	} 
	if(p->lchild && p->Rchild){
		BiTNode *q = p;
		fp = p;
		p = p->Rchild;
		while(p->lchild){
			fp = p;
			p = p->lchild;
		}
		q->data = p->data;
		if(fp->lchild == p ){
			fp->lchild = p->Rchild;
			free(p);
			printf("删除成功\n");
		}
		else if(fp->Rchild == p){
			fp->Rchild = p->Rchild;
			free(p);
			printf("删除成功\n");
		}
		return T;
	}
	
	if(!p ->lchild && !p->Rchild){
		if(p == T){
			free(T);
			printf("删除成功\n");
			return NULL;
		}
		if(fp->lchild == p){
			fp->lchild = NULL;
			free(p);
			printf("删除成功\n");
		}else if(fp->Rchild == p){
			fp->Rchild = NULL;
			free(p);
			printf("删除成功\n");
		}
		return T;
	}
	
	if( p ->lchild && !p->Rchild){
		if(T == p){
			T = p->lchild;
			p->lchild = NULL;
			free(p);
			printf("删除成功\n");
			return T;
		}
		if(fp->lchild == p){
			fp->Rchild = p->lchild;
			p->lchild = NULL;
			free(p);
			printf("删除成功\n");
		}
		else if(fp->Rchild == p){
			fp->Rchild = p->lchild;
			p->lchild=NULL;
			free(p);
			printf("删除成功\n");
		}
		return T;
	}
	
	if(!p->lchild && p->Rchild){
		if(T==p){
			T = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("删除成功\n");
			return T;
		}
		if(fp ->lchild ==p){
			fp->lchild = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("删除成功\n");
		}
		else if(fp->Rchild ==p){
			fp->Rchild = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("删除成功\n");
		}
		
		return T;
	}
} 


void menu(){
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t二叉排序树\n");
	printf("\t\t\t------------------------------------------\n");
	printf("\t\t\t-*1.插入结点      *******     2.先序遍历*-\n");
	printf("\t\t\t-*3.中序遍历      *******     4.后序遍历*-\n");
	printf("\t\t\t-*5.查询结点      *******     6.删除结点*-\n");
	printf("\t\t\t------------------------------------------\n");
}


void operate(){
	int oper;
	printf("请输入操作:");
	while((scanf("%d",&oper))!=1){
		printf("\n对不起你的输入有误,请重试：");
		fflush(stdin);
	} 
	switch(oper){
		case 1:
			int data;

			printf("\n请输入你要插入的数据:");
			while((scanf("%d",&data))!=1){
				printf("\n对不起你的输入有误,请重试：");
				fflush(stdin);
			}
			T = CreateTree(T,data);
			break;
		case 2:
			
			printf("\n树中的元素有:\n");
			PreOrderTraverse(T);
			break;
		case 3:
			printf("\n树中的元素有:\n");	
			InOrderTraverse(T);
			break;
		case 4:
			printf("\n树中的元素有:\n");
			PostOrderTraverse(T);
			break;
		case 5:
			int d;	
			printf("\n请输入你要查找的元素:");
			while((scanf("%d",&d))!=1){
				printf("\n对不起你的输入有误,请重试：");
				fflush(stdin);				
			}
			if(searchTree(T,d)){
				printf("有这个元素\n");
			}else{
				printf("没有这个元素\n");
			}
			break;
		case 6:
			printf("请输入需要删除的元素:");
			int number;
			while((scanf("%d",&number))!=1){
				printf("\n对不起你的输入有误,请重试：");
				fflush(stdin);				
			}
			DeleteTreeNode(T,number);
			break;	
		default:
			printf("您输入的操作不对\n");			
	}
}


int main(){

	while(1){
		menu();
		operate();
		system("pause");
		system("cls");
	}
}
