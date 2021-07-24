#include<stdio.h>
void swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
//快速排序法  前后指针版本
void QuickSort2(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int cur = begin, prev = begin - 1;
	int keyi = end;
	while (cur != keyi)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)
		{
			swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	swap(&arr[++prev],&arr[keyi]);
	keyi = prev;
	//[begin,keyi -1]keyi[keyi+1,end]
	QuickSort2(arr, begin, keyi - 1);
	QuickSort2(arr, keyi + 1, end);

}

//快速排序法  挖坑法
void QuickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin,right = end;
	int key = arr[begin];
	while (begin < end)
	{
		//找小
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		//小的放到左边的坑里
		arr[begin] = arr[end];
		//找大
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		//大的放到右边的坑里
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	int keyi = begin;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort1(arr, left, keyi - 1);
	QuickSort1(arr, keyi + 1, right);
}

//快速排序   hoare版本(左右指针法)
void QuickSort(int* arr, int begin, int end)
{
	//只有一个数或区间不存在
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	//选左边为key
	int keyi = begin;
	while (begin < end)
	{
		//右边选小   等号防止和key值相等    防止顺序begin和end越界
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//左边选大
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		//小的换到右边，大的换到左边
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[keyi], &arr[end]);
	keyi = end;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr,keyi + 1,right);
}



//冒泡排序
void BubbleSort(int* arr, int n)
{
	int end = n;
	while (end)
	{
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (arr[i - 1] > arr[i])
			{
				int tem = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = tem;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
		--end;
	}
}

//选择排序
void SelectSort(int* arr, int n)
{
	//保存参与单趟排序的第一个数和最后一个数的下标
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//保存最大值的下标
		int maxi = begin;
		//保存最小值的下标
		int mini = begin;
		//找出最大值和最小值的下标
		for (int i = begin; i <= end; ++i)
		{
			if (arr[i] < arr[mini])
			{
				mini = i;
			}
			if (arr[i] > arr[maxi])
			{
				maxi = i;
			}
		}
		//最小值放在序列开头
		swap(&arr[mini], &arr[begin]);
		//防止最大的数在begin位置被换走
		if (begin == maxi)
		{
			maxi = mini;
		}
		//最大值放在序列结尾
		swap(&arr[maxi], &arr[end]);
		++begin;
		--end;
	}
}

//希尔排序
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap)
	{
		//每次对gap折半操作
		gap = gap / 2;
		//单趟排序
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tem = arr[end + gap];
			while (end >= 0)
			{
				if (tem < arr[end])
				{
					arr[end + gap] = arr[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			arr[end + gap] = tem;
		}
	}
}

//插入排序
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//记录有序序列最后一个元素的下标
		int end = i;
		//待插入的元素
		int tem = arr[end + 1];
		//单趟排
		while (end >= 0)
		{
			//比插入的数大就向后移
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//比插入的数小，跳出循环
			else
			{
				break;
			}
		}
		//tem放到比插入的数小的数的后面
		arr[end  + 1] = tem;
		//代码执行到此位置有两种情况:
		//1.待插入元素找到应插入位置（break跳出循环到此）
		//2.待插入元素比当前有序序列中的所有元素都小（while循环结束后到此）
	}
}

int main()
{
	int arr[] = { 0, 4, 2, 8, 3, 7, 1, 6, 12, 53, 22, 41 ,7};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);//区间[0,n-1]
	//QuickSort1(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);//区间[0,n-1]
	QuickSort2(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);//区间[0,n-1]
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}