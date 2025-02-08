//堆排序扩展题目('小根堆'方法)
/*
  已知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
  并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

void sortedArrayDistanceLessK(vector<int>& arr, int k);
int main()
{
    vector<int> arr = {6,8,3,2,5,6,1,4,9};
    sortedArrayDistanceLessK(arr,6);
    for(int r : arr)
    {
        cout<<r<<" ";
    }
    return 0;
}

void sortedArrayDistanceLessK(vector<int>& arr, int k)
{
    priority_queue<int, vector<int>,greater<int>> heap;
    int index = 0;
    for(; index < min((int)arr.size(),k); index++) 
    {
        heap.push(arr[index]);
    }
    int i = 0;
    for(; index < (int)arr.size(); i++, index++) 
    {
        heap.push(arr[index]);
        arr[i] = heap.top();
        heap.pop();
    }
    while(!heap.empty()) 
    {
        arr[i++] = heap.top();
        heap.pop();
    }
}


