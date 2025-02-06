// 基数排序（桶排序）
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

// arr[begin...end]排序
void radixSort(vector<int>& arr, int L, int R, int digit)
{// digit是这一组数中，最大的数有几个十进制位
    int radix = 10;  // 以10为基底
    int i = 0, j = 0;
    vector<int> bucket(R - L + 1); // 有多少个数准备多少桶
    for(int d = 1; d <= digit; d++) // 有多少个十进制位，就入桶、出桶几次
    {
        // 10个空间
        // count[0] 当前位(d位)是0的数字有几个
        // count[1] 当前位(d位)是(0和1)的数字有几个
        // count[2] 当前位(d位)是(0、1和2)的数字有几个
        // count[i] 当前位(d位)是(0~i)的数字有几个
        vector<int> count(radix); // count[0..9]
        for(i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for(i = 1; i < radix; i++)
        {                           // 求出前缀和count数组用于记录每个数位上各个数字（0 到 9）出现的次数。
            count[i] += count[i-1]; // 通过这个循环，将count[i]的值更新为前i个数位上该数字出现的总次数。
        }                           // 这样，count[j]就表示了当前数位上小于等于j的数字出现的总次数。

        for(i = R; i >= L; i--) // 数组从右往左遍历
        {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i]; //count[j]表示当前数位上小于等于j的数字出现的总次数，那么count[j] - 1就是当前数位上值为j的数字应该放入桶中的位置。
            count[j]--; // 单个位的词频减减
        }
        for(i = L,j = 0; i <= R; i++,j++)
        {
            arr[i] = bucket[j]; // 将buket里的数据，导到数组里面
        }
    }
}


int getDigit(int x, int d)
{   //这个方法的目的是获取整数 x 的第 d 位数字。
    return ((x / ((int)pow(10, d - 1))) % 10);
}



