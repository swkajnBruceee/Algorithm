#include<stdio.h>

//������Ϊ��
void bubble_sort(int arr[],int sz)
{
	//ȷ��ð�����������
	int i = 0;
	for (i = 0;i < sz - 1;i++)
	{
		int flag = 1; //������һ��Ҫ����������Ѿ�����
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 0; //�������������ʵ��������
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
	/*һ��Ҫ��ǰ���������а�sz������������ں����н��м������ִ�����Ϊ����bubbli_sort��arr�������ʱ
	  ����ȥ�Ĳ����������飬����������׵�ַ�������ں�����֮�ڣ�arr/arr[0] == 1,��˻ᷢ������
	*/
	
	//��arr���������ų�����
	bubble_sort(arr,sz); //ð��������
	
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}