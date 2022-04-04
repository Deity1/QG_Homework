#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int *text;
	int n,i;
	int flag=0;
	while(1){
		system("cls");
		meau();
		switch(intput()){
			case 1:{
				printf("��������Ҫ����������Ĵ�С\n");
				scanf("%d",&n);
				text = (int*)malloc(sizeof(int)*n);
				CreatMatrix(text,n);
				printf("�������\n");
				flag=1;
				break;
			}
			case 2:{
				if(flag){
					insertSort(text,n);
					printf("�����������\n");
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 3:{
				if(flag){
					int k;
					printf("��������Ҫ��ѯ�ĵڼ������\n");
					scanf("%d",&k);
					Findnum(text,n,k);
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 4:{
				if(flag){
					int begin = 0;
					int *temp=(int*)malloc(sizeof(int)*n);
					clock_t start = clock();
					MergeSort(text,begin,n,temp);
					clock_t diff = clock() - start;
					printf("%d ms\n", diff);
					printf("�鲢�������\n");
					free(temp);   //�ͷſռ� 
					temp=NULL;
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 5:{
				if(flag){
					int begin = 0;
					clock_t start = clock();
					QuickSort_Recursion(text,begin, n);   // �������� 
					clock_t diff = clock() - start;
					printf("%d ms\n", diff);
					printf("�����������\n");
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 6:{
				if(flag){
					int max=text[0];
					CountSort(text,n,max);      // �������� 
					printf("�����������\n");
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 7:{
				if(flag){
					RadixCountSort(text,n);  // �������� 
				}
				else{
					printf("�������鹩����");
				}
				break;
			}
			case 8:{
				if(flag){
					print(text, n);    //������� 
				}
				break;
			}
			case 9:{
				int a[7] = {1,2,1,0,2,0,0};
				ColorSort(a,7);   //��ɫ���� 
				print(a,7);
				break;
			}
			case 0:{
				exit(0);
				break;
			}
			case 10:{
				new_text();
				break;
			}
			case 11:{
				if(flag){
					save_data(text,n);
				}
				break;
			}
			case 12:{
				read_data(text);
				break;
			} 
			default :break;
			
		}
		system("pause");
	}	
	return 0;
}
