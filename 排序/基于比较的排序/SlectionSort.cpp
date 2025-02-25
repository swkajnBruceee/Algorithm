// 选择排序
// 时间复杂度：O(N^2)
// 额外空间复杂度：O(1)

#include<iostream>
#include<vector>
using namespace std;

void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
} 



void selectionSort(vector<int>& arr)
{
    if(arr.size() < 2) return;
    for(int i = 0; i < (int)arr.size()-1; i++)
    {
        int minIndex = i;
        for(int j = i+1; j < (int)arr.size(); j++)
        {
            minIndex = arr[j] < arr[minIndex] ? j : minIndex;
        }
        swap(arr, i, minIndex);
    }
}





int main()
{
    vector<int> arr = {9,3,1,5,4,9};
    selectionSort(arr);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}





