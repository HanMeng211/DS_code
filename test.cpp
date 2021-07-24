#include<stdio.h>
void swap(int* a, int* b)
{
	int tem = *a;
	*a = *b;
	*b = tem;
}
//��������  ǰ��ָ��汾
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

//��������  �ڿӷ�
void QuickSort1(int* arr, int begin, int end)
{
	if (begin >= end)
		return;
	int left = begin,right = end;
	int key = arr[begin];
	while (begin < end)
	{
		//��С
		while (arr[end] >= key && begin < end)
		{
			--end;
		}
		//С�ķŵ���ߵĿ���
		arr[begin] = arr[end];
		//�Ҵ�
		while (arr[begin] <= key && begin < end)
		{
			++begin;
		}
		//��ķŵ��ұߵĿ���
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	int keyi = begin;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort1(arr, left, keyi - 1);
	QuickSort1(arr, keyi + 1, right);
}

//��������   hoare�汾(����ָ�뷨)
void QuickSort(int* arr, int begin, int end)
{
	//ֻ��һ���������䲻����
	if (begin >= end)
		return;
	int left = begin;
	int right = end;
	//ѡ���Ϊkey
	int keyi = begin;
	while (begin < end)
	{
		//�ұ�ѡС   �Ⱥŷ�ֹ��keyֵ���    ��ֹ˳��begin��endԽ��
		while (arr[end] >= arr[keyi] && begin < end)
		{
			--end;
		}
		//���ѡ��
		while (arr[begin] <= arr[keyi] && begin < end)
		{
			++begin;
		}
		//С�Ļ����ұߣ���Ļ������
		swap(&arr[begin], &arr[end]);
	}
	swap(&arr[keyi], &arr[end]);
	keyi = end;
	//[left,keyi-1]keyi[keyi+1,right]
	QuickSort(arr, left, keyi - 1);
	QuickSort(arr,keyi + 1,right);
}



//ð������
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

//ѡ������
void SelectSort(int* arr, int n)
{
	//������뵥������ĵ�һ���������һ�������±�
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		//�������ֵ���±�
		int maxi = begin;
		//������Сֵ���±�
		int mini = begin;
		//�ҳ����ֵ����Сֵ���±�
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
		//��Сֵ�������п�ͷ
		swap(&arr[mini], &arr[begin]);
		//��ֹ��������beginλ�ñ�����
		if (begin == maxi)
		{
			maxi = mini;
		}
		//���ֵ�������н�β
		swap(&arr[maxi], &arr[end]);
		++begin;
		--end;
	}
}

//ϣ������
void ShellSort(int* arr, int n)
{
	int gap = n;
	while (gap)
	{
		//ÿ�ζ�gap�۰����
		gap = gap / 2;
		//��������
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

//��������
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//��¼�����������һ��Ԫ�ص��±�
		int end = i;
		//�������Ԫ��
		int tem = arr[end + 1];
		//������
		while (end >= 0)
		{
			//�Ȳ��������������
			if (tem < arr[end])
			{
				arr[end + 1] = arr[end];
				end--;
			}
			//�Ȳ������С������ѭ��
			else
			{
				break;
			}
		}
		//tem�ŵ��Ȳ������С�����ĺ���
		arr[end  + 1] = tem;
		//����ִ�е���λ�����������:
		//1.������Ԫ���ҵ�Ӧ����λ�ã�break����ѭ�����ˣ�
		//2.������Ԫ�رȵ�ǰ���������е�����Ԫ�ض�С��whileѭ�������󵽴ˣ�
	}
}

int main()
{
	int arr[] = { 0, 4, 2, 8, 3, 7, 1, 6, 12, 53, 22, 41 ,7};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	//QuickSort(arr, 0, sizeof(arr) / sizeof(arr[0])-1);//����[0,n-1]
	//QuickSort1(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);//����[0,n-1]
	QuickSort2(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1);//����[0,n-1]
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}