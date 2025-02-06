#include<stdio.h>

//以升序为例
void bubble_sort(int arr[],int sz)
{
	//确定冒泡排序的趟数
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int flag = 1; //假设这一趟要排序的数据已经有序
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0; //本趟排序的数其实并不有序
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
}


int main()
{
	int arr[] = { 9,7,6,8,3,4,1,2 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	/*一定要提前在主函数中把sz计算出来，若在函数中进行计算会出现错误，因为在用bubbli_sort传arr这个参数时
	  传进去的不是整个数组，而是数组的首地址，所以在函数体之内，arr/arr[0] == 1,因此会发生错误
	*/
	
	//对arr进行排序，排成升序
	bubble_sort(arr,sz); //冒泡排序函数
	
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}