// 堆排序(以'大根堆为例')
// 时间复杂度：O(N*logN)
// 额外空间复杂度：O(1)
#include<iostream>
#include<vector>
using namespace std;

void heapSort(vector<int>& arr);
void heapInsert(vector<int>& arr, int index);
void swap(vector<int>& arr, int i, int j);
void heapify(vector<int>& arr, int index, int heapSize);

int main()
{
    vector<int> arr = { 6, 3, 6, 7, 9, 1 };
    heapSort(arr);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}


void heapSort(vector<int>& arr)
{
    if(arr.size() < 2) return;

    //1. 将整个数组变成'大根堆'
    for(int i = 0; i < (int)arr.size(); i++) // O(N)
    {
        heapInsert(arr, i); // O(logN)
        // 也可以不用函数的方法，直接创建一个priority_queue就是大根堆
    }

    int heapSize = arr.size();
    swap(arr, 0, --heapSize); // 将数组0位置的数(即最大数) 与数组最后位置的数交换
    while(heapSize > 0)  // O(N)
    { 
        heapify(arr, 0, heapSize); // O(logN)
        swap(arr, 0, --heapSize); // O(1)
    }

}


// 某个数现在处在index位置，往上继续移动
void heapInsert(vector<int>& arr, int index)
{
    while(arr[index] > arr[(index-1)/2])// (index-1)/2 是index位置的父位置
    { 
        swap(arr, index, (index-1)/2);
        index = (index-1)/2;
    }
}


// 某个数在index位置，能否向下移动  (此操作可以在用户删掉最大值后，重新使这个堆变为'大根堆')
void heapify(vector<int>& arr, int index, int heapSize)
{   // heapSize管理着堆的大小
    int left = index * 2 + 1; // 左孩子的下标
    while (left < heapSize)  // 下方还有孩子时
    { 
        // 两个孩子中，谁的值大，把下标给largest
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        // 父和孩子之间，谁的值大，把下标给largest
        largest = arr[largest] > arr[index] ? largest : index;
        if(largest == index) break;           
        swap(arr,largest,index);
        index = largest; // index往下走
        left = index * 2 + 1;
    }
}


void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}






