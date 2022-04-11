#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode{
	int data;
	struct BiTNode *lchild,*Rchild;
}BiTNode;

	BiTNode *
	T ;

//�������������� 
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
		printf("��Ԫ���Ѿ�������\n");
	}
	return T;
}

//���������������������
void PreOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	printf("%d\t",T->data);
	PreOrderTraverse(T->lchild);
	PreOrderTraverse(T->Rchild);
} 

//���������������������
void InOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	InOrderTraverse(T->lchild);
	printf("%d\t",T->data);
	InOrderTraverse(T->Rchild);
} 

//���������������������
void PostOrderTraverse(BiTNode *T){
	if(T==NULL){
		return;
	}
	InOrderTraverse(T->lchild);
	InOrderTraverse(T->Rchild);
	printf("%d\t",T->data);
} 

//������ 
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


//ɾ�����
BiTNode *DeleteTreeNode(BiTNode *T,int n){
	if(T==NULL){
		return NULL;
	}
	BiTNode *p = NULL;
	BiTNode *fp = NULL;
	p = T;
	
	while(1){//Ѱ��Ҫɾ����λ�� 
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
			printf("ɾ���ɹ�\n");
		}
		else if(fp->Rchild == p){
			fp->Rchild = p->Rchild;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		return T;
	}
	
	if(!p ->lchild && !p->Rchild){
		if(p == T){
			free(T);
			printf("ɾ���ɹ�\n");
			return NULL;
		}
		if(fp->lchild == p){
			fp->lchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}else if(fp->Rchild == p){
			fp->Rchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		return T;
	}
	
	if( p ->lchild && !p->Rchild){
		if(T == p){
			T = p->lchild;
			p->lchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
			return T;
		}
		if(fp->lchild == p){
			fp->Rchild = p->lchild;
			p->lchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		else if(fp->Rchild == p){
			fp->Rchild = p->lchild;
			p->lchild=NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		return T;
	}
	
	if(!p->lchild && p->Rchild){
		if(T==p){
			T = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
			return T;
		}
		if(fp ->lchild ==p){
			fp->lchild = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		else if(fp->Rchild ==p){
			fp->Rchild = p->Rchild;
			p->Rchild = NULL;
			free(p);
			printf("ɾ���ɹ�\n");
		}
		
		return T;
	}
} 


void menu(){
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t����������\n");
	printf("\t\t\t------------------------------------------\n");
	printf("\t\t\t-*1.������      *******     2.�������*-\n");
	printf("\t\t\t-*3.�������      *******     4.�������*-\n");
	printf("\t\t\t-*5.��ѯ���      *******     6.ɾ�����*-\n");
	printf("\t\t\t------------------------------------------\n");
}


void operate(){
	int oper;
	printf("���������:");
	while((scanf("%d",&oper))!=1){
		printf("\n�Բ��������������,�����ԣ�");
		fflush(stdin);
	} 
	switch(oper){
		case 1:
			int data;

			printf("\n��������Ҫ���������:");
			while((scanf("%d",&data))!=1){
				printf("\n�Բ��������������,�����ԣ�");
				fflush(stdin);
			}
			T = CreateTree(T,data);
			break;
		case 2:
			
			printf("\n���е�Ԫ����:\n");
			PreOrderTraverse(T);
			break;
		case 3:
			printf("\n���е�Ԫ����:\n");	
			InOrderTraverse(T);
			break;
		case 4:
			printf("\n���е�Ԫ����:\n");
			PostOrderTraverse(T);
			break;
		case 5:
			int d;	
			printf("\n��������Ҫ���ҵ�Ԫ��:");
			while((scanf("%d",&d))!=1){
				printf("\n�Բ��������������,�����ԣ�");
				fflush(stdin);				
			}
			if(searchTree(T,d)){
				printf("�����Ԫ��\n");
			}else{
				printf("û�����Ԫ��\n");
			}
			break;
		case 6:
			printf("��������Ҫɾ����Ԫ��:");
			int number;
			while((scanf("%d",&number))!=1){
				printf("\n�Բ��������������,�����ԣ�");
				fflush(stdin);				
			}
			DeleteTreeNode(T,number);
			break;	
		default:
			printf("������Ĳ�������\n");			
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
