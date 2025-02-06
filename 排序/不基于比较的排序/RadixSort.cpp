// ��������Ͱ����
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void radixSort(vector<int>& arr);
void radixSort(vector<int>& arr, int L, int R, int digit);
int maxbits(vector<int>& arr);
int getDigit(int x, int d);

int main()
{
    vector<int> arr = {4,2,7,5,5,6,3,8,9};
    radixSort(arr, 0, arr.size()-1, maxbits(arr));
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}

// only for no-negative value
void radixSort(vector<int>& arr)
{
    if(arr.empty()) return;
    radixSort(arr, 0, arr.size()-1, maxbits(arr));
}


int maxbits(vector<int>& arr)
{
    int maxValue = arr[0];
    for(int i=0;i < (int)arr.size();i++)
    {
        maxValue = max(maxValue, arr[i]);
    }
    int res = 0;
    while(maxValue != 0)
    {
        res++;
        maxValue /= 10;
    }
    return res;
}

// arr[begin...end]����
void radixSort(vector<int>& arr, int L, int R, int digit)
{// digit����һ�����У��������м���ʮ����λ
    int radix = 10;  // ��10Ϊ����
    int i = 0, j = 0;
    vector<int> bucket(R - L + 1); // �ж��ٸ���׼������Ͱ
    for(int d = 1; d <= digit; d++) // �ж��ٸ�ʮ����λ������Ͱ����Ͱ����
    {
        // 10���ռ�
        // count[0] ��ǰλ(dλ)��0�������м���
        // count[1] ��ǰλ(dλ)��(0��1)�������м���
        // count[2] ��ǰλ(dλ)��(0��1��2)�������м���
        // count[i] ��ǰλ(dλ)��(0~i)�������м���
        vector<int> count(radix); // count[0..9]
        for(i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for(i = 1; i < radix; i++)
        {                           // ���ǰ׺��count�������ڼ�¼ÿ����λ�ϸ������֣�0 �� 9�����ֵĴ�����
            count[i] += count[i-1]; // ͨ�����ѭ������count[i]��ֵ����Ϊǰi����λ�ϸ����ֳ��ֵ��ܴ�����
        }                           // ������count[j]�ͱ�ʾ�˵�ǰ��λ��С�ڵ���j�����ֳ��ֵ��ܴ�����

        for(i = R; i >= L; i--) // ��������������
        {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i]; //count[j]��ʾ��ǰ��λ��С�ڵ���j�����ֳ��ֵ��ܴ�������ôcount[j] - 1���ǵ�ǰ��λ��ֵΪj������Ӧ�÷���Ͱ�е�λ�á�
            count[j]--; // ����λ�Ĵ�Ƶ����
        }
        for(i = L,j = 0; i <= R; i++,j++)
        {
            arr[i] = bucket[j]; // ��buket������ݣ�������������
        }
    }
}


int getDigit(int x, int d)
{   //���������Ŀ���ǻ�ȡ���� x �ĵ� d λ���֡�
    return ((x / ((int)pow(10, d - 1))) % 10);
}



