// »ùÊýÅÅÐò£¨Í°ÅÅÐò£©
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

// arr[begin...end]ÅÅÐò
void radixSort(vector<int>& arr, int L, int R, int digit)
{
    int radix = 10;
    int i = 0, j = 0;
    vector<int> bucket(R - L + 1);
    for(int d = 1; d <= digit; d++)
    {
        vector<int> count(radix);
        for(i = L; i <= R; i++)
        {
            j = getDigit(arr[i], d);
            count[j]++;
        }
        for(i = 1; i < radix; i++)
        {
            count[i] += count[i-1];
        }
        for(i = R; i >= L; i--)
        {
            j = getDigit(arr[i], d);
            bucket[count[j] - 1] = arr[i];
            count[j]--;
        }
        for(i = L,j = 0; i <= R; i++,j++)
        {
            arr[i] = bucket[j];
        }
    }
}


int getDigit(int x, int d)
{
    return ((x / ((int)pow(10, d - 1))) % 10);
}



