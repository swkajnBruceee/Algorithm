//��������չ��Ŀ('С����'����)
/*
  ��֪һ��������������飬����������ָ������������ź�˳��Ļ���ÿ��Ԫ���ƶ��ľ�����Բ�����k��
  ����k�����������˵�Ƚ�С����ѡ��һ�����ʵ������㷨���������ݽ�������
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


