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
				printf("请输入你要创建的数组的大小\n");
				scanf("%d",&n);
				text = (int*)malloc(sizeof(int)*n);
				CreatMatrix(text,n);
				printf("创建完成\n");
				flag=1;
				break;
			}
			case 2:{
				if(flag){
					insertSort(text,n);
					printf("插入排序完成\n");
				}
				else{
					printf("暂无数组供排序");
				}
				break;
			}
			case 3:{
				if(flag){
					int k;
					printf("请输入你要查询的第几大的数\n");
					scanf("%d",&k);
					Findnum(text,n,k);
				}
				else{
					printf("暂无数组供排序");
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
					printf("归并排序完成\n");
					free(temp);   //释放空间 
					temp=NULL;
				}
				else{
					printf("暂无数组供排序");
				}
				break;
			}
			case 5:{
				if(flag){
					int begin = 0;
					clock_t start = clock();
					QuickSort_Recursion(text,begin, n);   // 快速排序 
					clock_t diff = clock() - start;
					printf("%d ms\n", diff);
					printf("快速排序完成\n");
				}
				else{
					printf("暂无数组供排序");
				}
				break;
			}
			case 6:{
				if(flag){
					int max=text[0];
					CountSort(text,n,max);      // 计数排序 
					printf("计数排序完成\n");
				}
				else{
					printf("暂无数组供排序");
				}
				break;
			}
			case 7:{
				if(flag){
					RadixCountSort(text,n);  // 基数排序 
				}
				else{
					printf("暂无数组供排序");
				}
				break;
			}
			case 8:{
				if(flag){
					print(text, n);    //输出函数 
				}
				break;
			}
			case 9:{
				int a[7] = {1,2,1,0,2,0,0};
				ColorSort(a,7);   //颜色排序 
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
