#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <windows.h>


// �������� 
void insertSort(int *a,int n){
	// ��ʼ��ʱ�� 
	clock_t start = clock();
	int i,h;
	// �����㷨��ʵ�� 
	for(i=0;i < n-1; ++i){
		int end = i;
		int x = a[end+1];
		while(end >= 0){    //  
			if(a[end] > x){
				a[end + 1] = a[end];  // �����滻 
				--end;
			}
			else{
				break;
			}
		}
		a[end + 1] = x;
	}
	// ������ʱ 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff); 
}
// �鲢���� 
void MergeSort(int *a,int begin,int end,int *temp){
	// ��ʼ��ʱ�� 
	// �鲢������Ҫ��������������,������ǰ������һ��ռ���Ϊ 
	if(begin>=end){
		return;   // �������ڵݹ鵽����ָ��ͬһ������ 
	}
	int mid = (begin + end)/2;
	// ��ô���䱻����Ϊ��  begin,mid , mid+1,end �������� 
	MergeSort(a,begin,mid,temp);   // �ֱ�ݹ���н��� 
	MergeSort(a,mid+1,end,temp);

	//�ϲ����� 
	MergeArray(a,begin,mid,end,temp);
	// ������ʱ 	
}
// �ϲ����� 
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i=begin;
	int begin1=begin,end1 = mid;
	int begin2=mid+1,end2=end;
	int j;
	while(begin1 <=end1 && begin2 <= end2){
		if(a[begin1]<a[begin2]){   // ���ｫ����ֳ��������ֽ����ж� �����һ���������С�������ʱ�������� 
			temp[i++]=a[begin1++];   
		}
		else{
			temp[i++]=a[begin2++];
		}
	} 
	while(begin1<=end1){     //   
		temp[i++]=a[begin1++];
	}
	while(begin2<=end2){
		temp[i++]=a[begin2++];
	}
	for(j=begin;j<=end;++j){
		a[j]=temp[j];
	}	
}
// ���ŵݹ�� 
void QuickSort_Recursion(int *a, int begin, int end){
	// ��ʼ��ʱ�� 
//	clock_t start = clock();
	// �ݹ���������� 
	if(begin >= end){
		return;
	}
	int mid = Partition(a,begin,end);  
	QuickSort_Recursion(a,begin,mid-1);
	QuickSort_Recursion(a,mid+1,end);
	// ������ʱ 
//	clock_t diff = clock() - start;
//	printf("%d ms\n", diff);	
	
}
int Partition(int *a, int begin, int end){
	int mid = GetMidIndex(a,begin,end);
	int temp;
	temp = a[begin];a[begin] = a[mid];a[mid] = temp;
	int key = begin;
	while(begin < end){
		//  �ȴ��ұ߿�ʼ�ұ�ͷС���� 
		while(begin < end && a[end] >= a[key]){
			--end;
		}
		//  ������ҵ�һ���������С�Ľ��� 
		while(begin < end && a[begin] <= a[key]){
			++begin;
		}
		temp = a[begin];a[begin] = a[end];a[end] = temp;
	}
	temp = a[begin];a[begin] = a[mid];a[mid] = temp;
	return begin;
}
// ����ȡ�� 
int GetMidIndex(int *a,int begin,int end){
	int mid = begin + ((end - begin)>>1);  // ���Ʋ������ڡ�2 
	if(a[begin] < a[mid]){
		if(a[mid] < a[end]){
			return mid;
		}
		else if(a[begin] > a[end]){
			return begin;
		}
		else{
			return end;
		}
	}
	else{
		if(a[mid] > a[end]){
			return mid;
		}
		else if(a[begin] < a[end]){
			return begin;
		}
		else{
			return end;
		}
	}
	
}
// �������� 
void CountSort(int *a, int size , int max){
	// ��ʼ��ʱ�� 
	clock_t start = clock();
	int i,j=0;
	int min=a[0];
	for(i=0;i<size;i++){   //���ݼ��������㷨��ԭ����л�ȡ��Χ 
		if(a[i]>max){
			max = a[i];
		}
		if(a[i]<min){
			min = a[i];
		}
	}
	int range = max - min + 1; 
	int *count = (int*)malloc(sizeof(int)*range);  // �������跶Χ��ô��Ŀռ� 
	for(i=0;i<range;i++){
		count[i]=0;   // ��������������Ϊ0 
	}
	for(i=0;i<size;++i){
		count[a[i]-min]++;  // ͳ�����ݳ��ֵĸ��� 
	}
	for(i=0;i<range;++i){
		while(count[i]--){   // ��Ϊ�����ĵط�����0�������ж�ѭ���������ͺ��� 
			a[j++] = i+min;
		}
	}
		// ������ʱ 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
}
int get_index(int a,int digit){
	while(digit > 1){
		a /= 10;
		digit--;
	}
	return a%10;
}
//  �������� 
void RadixCountSort(int *a,int size){
	// ��ʼ��ʱ�� 
	clock_t start = clock();
	int count[10][size]; // ����һ��2ά��������Ÿ���ʮ����..������
	int i,j,l,k,digit,max=a[0];
	int flag=1; 
	int n=0; // ��Ϊ���λ����ͳ�� 
	// ��ʼ���������� 
	memset(count,0,sizeof(count)); 
	for(i=0;i<size;i++){
		if(a[i]>max){
			max = a[i];   // ����ط���Ϊ���ҵ������� 
		}
	}
	// ���λ��
	while(flag){
		max = max/10;
		if(max==0){
			flag = 0;
			break;
		}
		n++;
	} 
	for(i=1;i<=n;i++){   // һ��Ҫѭ��(λ����--���λ�Ĵ�С) 
		for(j=0;j<size;j++){    
			digit = get_index(a[j],i);  // ��ȡ��λ��ʮλ...������ 
			k = 0;
			while(count[digit][k])       //  ������б��� �ҵ��յ�λ�ò������� 
				k++;
			count[digit][k] = a[j];     // ������Ӧ������ 
		}
		l = 0;
		for(j=0;j<10;j++){
			k=0;
			while(count[j][k]>0){
				a[l++] = count[j][k];    // �����ǽ�������ɺ����������ԭ���鵱�� 
				k++;
			}
		}
		memset(count,0,sizeof(count));   // �ٴγ�ʼ������ 
	}
		// ������ʱ 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
} 
// ��ɫ���� 
void ColorSort(int *a,int size){
		// ��ʼ��ʱ�� 
	clock_t start = clock();
	int p1=0,p0=0,p2=size-1; //һ������������������ 
	int i,temp;	
	for(i=0;i<=p2;i++){
		if(a[i]==0){
			temp = a[i];
			a[i] = a[p1];
			a[p1] = temp;
			p1++;
		}
		else if(a[i]==2){
			temp = a[p2];
			a[p2] = a[i];
			a[i] = temp;
			p2--;
			i--; 
		}
	}
	// ������ʱ 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
}
// �ҵ���k����� 
void Findnum(int *a,int size, int k){
		// ��ʼ��ʱ�� 
	clock_t start = clock();
	int begin=0;
//	insertSort(a,size); 
	QuickSort_Recursion(a,begin,size);  //  ���������ѯ 
	printf("��%d�������%d\n",k,a[size-k]);
// ������ʱ 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
}


// �����������
void CreatMatrix(int *a,int n){
	int i,num;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		num = rand() % 200 + 1;
		a[i] = num;
	}
} 
// ������� 
void print(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d  ",a[i]);
		if(i==20){
			printf("\n");
		}
	}
	printf("\n");
}
void save_data(int *a,int size){
	FILE *fp=fopen("data.txt","r");
	if((fp=fopen("data.txt","r"))==NULL){
		printf("��д���ļ�ʧ��\n");
		return ;
	}
	int i;
	while(!feof(fp)){
		for(i=0;i<size;i++)
		fprintf(fp,"%d",a[i]);
	}
	printf("¼�����\n");
	fclose(fp);
}
void read_data(int *a){
	FILE *fp=fopen("data.txt","w");
	if((fp=fopen("data.txt","w"))==NULL){
		printf("��д���ļ�ʧ��\n");
	}
	int i;
	fscanf(fp,"%d",a[i]);
	printf("��ȡ���ݳɹ�\n");
	fclose(fp);
} 
void new_text(){
	int size;
	printf("��������Ҫ���Ե����ݵĴ�С\n");
	scanf("%d",&size);
	int *train = (int*)malloc(sizeof(int)*size);
	int *temp = (int*)malloc(sizeof(int)*size);
	CreatMatrix(train,size);
	int end=size;
	int begin=0;
	int max=train[0];
	printf("���������ʱ����Ҫ�����ĵȴ�\n");
	
	printf("����������ʱ:\n");
	insertSort(train,size);
	
	CreatMatrix(train,size);  // ��ʼ�� 
	clock_t start = clock();
	printf("����������ʱ:\n");
	QuickSort_Recursion(train,begin, size);	
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
	
	CreatMatrix(train,size);  //��ʼ�� 
	printf("��������\n");
	CountSort(train,size,max);
	
	CreatMatrix(train,size);  // ��ʼ�� 
	printf("����������ʱ:\n");
	RadixCountSort(train,size);
	
	CreatMatrix(train,size); // ��ʼ��
	printf("�鲢����\n");
	clock_t start1 = clock();
	MergeSort(train,begin,size,temp);
	clock_t diff1 = clock() - start1;
	printf("%d ms\n", diff1); 
} 
void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("    ����������С��������������ɵ�ʱ���Զ���  \n");
	printf("**********************************************\n");
	printf("*  1.�����������        *  *   2.��������   *\n");
	printf("**********************************************\n");
	printf("*  3.Ѱ�ҵ�k�������     *  *   4.�鲢����   *\n");
	printf("**********************************************\n");
	printf("*  5.��������(�ݹ��)    *  *   6.��������   *\n");
	printf("**********************************************\n");
	printf("*  7.��������            *  *   8.��ʾ����   *\n");
	printf("**********************************************\n");
	printf("*                   9.��ɫ����               *\n");
	printf("**********************************************\n");
	printf("*                   10.һ������             **\n");
	printf("**********************************************\n");
	printf("*11.��������             * *    12.��ȡ����  *\n");
	printf("**********************************************\n");
	printf("*                   0.�˳�ϵͳ               *\n");
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
				if(s[i]<'0'||s[i]>'9'){
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
				if(i>=9){
					printf("������Χ��\n");
					status = 0;
				}
			}
		}
	}while(status == 0);
	return num;
}
