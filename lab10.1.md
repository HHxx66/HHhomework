# 快速排序

```
#include<stdio.h>
int partion(int arr[],int low,int high);
void quickSort(int arr[],int low,int high);
int main(){
	int n,i,arr[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quickSort(arr,0,n-1);
	for(i=0;i<n-1;i++){
		printf("%d ",arr[i]);
	}
	printf("%d\n",arr[n-1]);
	return 0;
}
void quickSort(int arr[],int low,int high){
	int part;
	if(high>low){
		part=partion(arr,low,high);
		quickSort(arr,low,part-1);
		quickSort(arr,part+1,high);
	}
}
int partion(int arr[],int low,int high){
	int temp=arr[low];
	while(low<high){
		while(low<high&&arr[high]>=temp){
			high--;
		}
		arr[low]=arr[high];
		while(low<high&&arr[low]<=temp){
			low++;
		}
		arr[high]=arr[low];
	}
	arr[low]=temp;
	return low;
}
```

### 原理：

运用递归的方法，每次选取一个数把数组分成两个区间，左边的数全比该数要小，右边的数全比该数要大，直到不能再分为止。

### 形象描述：

把一堆苹果由大到小排列，选取第一个苹果出来，把比该苹果大的放在它的左边，小的放在右边。然后再对左边右边的两堆苹果做同样的操作，直到不能再分为止，此时苹果就已经由大到小排好序了。