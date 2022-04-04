#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include <time.h>
#include <windows.h>


// 插入排序 
void insertSort(int *a,int n){
	// 开始的时间 
	clock_t start = clock();
	int i,h;
	// 排序算法的实现 
	for(i=0;i < n-1; ++i){
		int end = i;
		int x = a[end+1];
		while(end >= 0){    //  
			if(a[end] > x){
				a[end + 1] = a[end];  // 进行替换 
				--end;
			}
			else{
				break;
			}
		}
		a[end + 1] = x;
	}
	// 计算用时 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff); 
}
// 归并排序 
void MergeSort(int *a,int begin,int end,int *temp){
	// 开始的时间 
	// 归并排序需要有两个排序序列,所以提前开辟了一块空间作为 
	if(begin>=end){
		return;   // 这里是在递归到两个指向同一个顶峰 
	}
	int mid = (begin + end)/2;
	// 那么区间被划分为了  begin,mid , mid+1,end 两个部分 
	MergeSort(a,begin,mid,temp);   // 分别递归进行交换 
	MergeSort(a,mid+1,end,temp);

	//合并数组 
	MergeArray(a,begin,mid,end,temp);
	// 计算用时 	
}
// 合并数组 
void MergeArray(int *a,int begin,int mid,int end,int *temp){
	int i=begin;
	int begin1=begin,end1 = mid;
	int begin2=mid+1,end2=end;
	int j;
	while(begin1 <=end1 && begin2 <= end2){
		if(a[begin1]<a[begin2]){   // 这里将数组分成两个部分进行判断 如果第一个数组的最小则存入临时的数组中 
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
// 快排递归版 
void QuickSort_Recursion(int *a, int begin, int end){
	// 开始的时间 
//	clock_t start = clock();
	// 递归结束的条件 
	if(begin >= end){
		return;
	}
	int mid = Partition(a,begin,end);  
	QuickSort_Recursion(a,begin,mid-1);
	QuickSort_Recursion(a,mid+1,end);
	// 计算用时 
//	clock_t diff = clock() - start;
//	printf("%d ms\n", diff);	
	
}
int Partition(int *a, int begin, int end){
	int mid = GetMidIndex(a,begin,end);
	int temp;
	temp = a[begin];a[begin] = a[mid];a[mid] = temp;
	int key = begin;
	while(begin < end){
		//  先从右边开始找比头小的数 
		while(begin < end && a[end] >= a[key]){
			--end;
		}
		//  从左边找到一个大的数和小的交换 
		while(begin < end && a[begin] <= a[key]){
			++begin;
		}
		temp = a[begin];a[begin] = a[end];a[end] = temp;
	}
	temp = a[begin];a[begin] = a[mid];a[mid] = temp;
	return begin;
}
// 三数取中 
int GetMidIndex(int *a,int begin,int end){
	int mid = begin + ((end - begin)>>1);  // 右移并不等于、2 
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
// 计数排序 
void CountSort(int *a, int size , int max){
	// 开始的时间 
	clock_t start = clock();
	int i,j=0;
	int min=a[0];
	for(i=0;i<size;i++){   //根据计数排序算法的原理进行获取范围 
		if(a[i]>max){
			max = a[i];
		}
		if(a[i]<min){
			min = a[i];
		}
	}
	int range = max - min + 1; 
	int *count = (int*)malloc(sizeof(int)*range);  // 开辟所需范围那么大的空间 
	for(i=0;i<range;i++){
		count[i]=0;   // 将计数的数组置为0 
	}
	for(i=0;i<size;++i){
		count[a[i]-min]++;  // 统计数据出现的个数 
	}
	for(i=0;i<range;++i){
		while(count[i]--){   // 因为其它的地方都是0，拿来判断循环的条件就好了 
			a[j++] = i+min;
		}
	}
		// 计算用时 
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
//  基数排序 
void RadixCountSort(int *a,int size){
	// 开始的时间 
	clock_t start = clock();
	int count[10][size]; // 创建一个2维数组来存放个，十，百..的数据
	int i,j,l,k,digit,max=a[0];
	int flag=1; 
	int n=0; // 作为最高位数的统计 
	// 初始化分配数组 
	memset(count,0,sizeof(count)); 
	for(i=0;i<size;i++){
		if(a[i]>max){
			max = a[i];   // 这个地方是为了找到最大的数 
		}
	}
	// 获得位数
	while(flag){
		max = max/10;
		if(max==0){
			flag = 0;
			break;
		}
		n++;
	} 
	for(i=1;i<=n;i++){   // 一共要循环(位数次--最高位的大小) 
		for(j=0;j<size;j++){    
			digit = get_index(a[j],i);  // 获取个位、十位...的数字 
			k = 0;
			while(count[digit][k])       //  对其进行遍历 找到空的位置插入数据 
				k++;
			count[digit][k] = a[j];     // 填入相应的数据 
		}
		l = 0;
		for(j=0;j<10;j++){
			k=0;
			while(count[j][k]>0){
				a[l++] = count[j][k];    // 这里是将排序完成后的数组插入会原数组当中 
				k++;
			}
		}
		memset(count,0,sizeof(count));   // 再次初始化数组 
	}
		// 计算用时 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
} 
// 颜色排序 
void ColorSort(int *a,int size){
		// 开始的时间 
	clock_t start = clock();
	int p1=0,p0=0,p2=size-1; //一共有三个索引来排序 
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
	// 计算用时 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
}
// 找到第k大的数 
void Findnum(int *a,int size, int k){
		// 开始的时间 
	clock_t start = clock();
	int begin=0;
//	insertSort(a,size); 
	QuickSort_Recursion(a,begin,size);  //  快速排序查询 
	printf("第%d大的数是%d\n",k,a[size-k]);
// 计算用时 
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
}


// 创建随机数组
void CreatMatrix(int *a,int n){
	int i,num;
	srand(time(NULL));
	for (i = 0; i < n; i++)
	{
		num = rand() % 200 + 1;
		a[i] = num;
	}
} 
// 输出函数 
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
		printf("打开写入文件失败\n");
		return ;
	}
	int i;
	while(!feof(fp)){
		for(i=0;i<size;i++)
		fprintf(fp,"%d",a[i]);
	}
	printf("录入完成\n");
	fclose(fp);
}
void read_data(int *a){
	FILE *fp=fopen("data.txt","w");
	if((fp=fopen("data.txt","w"))==NULL){
		printf("打开写入文件失败\n");
	}
	int i;
	fscanf(fp,"%d",a[i]);
	printf("读取数据成功\n");
	fclose(fp);
} 
void new_text(){
	int size;
	printf("请输入你要测试的数据的大小\n");
	scanf("%d",&size);
	int *train = (int*)malloc(sizeof(int)*size);
	int *temp = (int*)malloc(sizeof(int)*size);
	CreatMatrix(train,size);
	int end=size;
	int begin=0;
	int max=train[0];
	printf("数据量大的时候需要你耐心等待\n");
	
	printf("插入排序用时:\n");
	insertSort(train,size);
	
	CreatMatrix(train,size);  // 初始化 
	clock_t start = clock();
	printf("快速排序用时:\n");
	QuickSort_Recursion(train,begin, size);	
	clock_t diff = clock() - start;
	printf("%d ms\n", diff);
	
	CreatMatrix(train,size);  //初始化 
	printf("计数排序\n");
	CountSort(train,size,max);
	
	CreatMatrix(train,size);  // 初始化 
	printf("基数排序用时:\n");
	RadixCountSort(train,size);
	
	CreatMatrix(train,size); // 初始化
	printf("归并排序\n");
	clock_t start1 = clock();
	MergeSort(train,begin,size,temp);
	clock_t diff1 = clock() - start1;
	printf("%d ms\n", diff1); 
} 
void meau(){
	printf("----------------------------------------------\n");
	printf("**********************************************\n");
	printf("    测试样本大小请在随机数组生成的时候自定义  \n");
	printf("**********************************************\n");
	printf("*  1.生成随机数组        *  *   2.插入排序   *\n");
	printf("**********************************************\n");
	printf("*  3.寻找第k大的数据     *  *   4.归并排序   *\n");
	printf("**********************************************\n");
	printf("*  5.快速排序(递归版)    *  *   6.计数排序   *\n");
	printf("**********************************************\n");
	printf("*  7.基数排序            *  *   8.显示数组   *\n");
	printf("**********************************************\n");
	printf("*                   9.颜色排序               *\n");
	printf("**********************************************\n");
	printf("*                   10.一并计算             **\n");
	printf("**********************************************\n");
	printf("*11.保存数据             * *    12.读取数据  *\n");
	printf("**********************************************\n");
	printf("*                   0.退出系统               *\n");
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
				if(i>=9){
					printf("超出范围了\n");
					status = 0;
				}
			}
		}
	}while(status == 0);
	return num;
}
