// ������(��'�����Ϊ��')
// ʱ�临�Ӷȣ�O(N*logN)
// ����ռ临�Ӷȣ�O(1)
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

    //1. ������������'�����'
    for(int i = 0; i < (int)arr.size(); i++) // O(N)
    {
        heapInsert(arr, i); // O(logN)
        // Ҳ���Բ��ú����ķ�����ֱ�Ӵ���һ��priority_queue���Ǵ����
    }

    int heapSize = arr.size();
    swap(arr, 0, --heapSize); // ������0λ�õ���(�������) ���������λ�õ�������
    while(heapSize > 0)  // O(N)
    { 
        heapify(arr, 0, heapSize); // O(logN)
        swap(arr, 0, --heapSize); // O(1)
    }

}


// ĳ�������ڴ���indexλ�ã����ϼ����ƶ�
void heapInsert(vector<int>& arr, int index)
{
    while(arr[index] > arr[(index-1)/2])// (index-1)/2 ��indexλ�õĸ�λ��
    { 
        swap(arr, index, (index-1)/2);
        index = (index-1)/2;
    }
}


// ĳ������indexλ�ã��ܷ������ƶ�  (�˲����������û�ɾ�����ֵ������ʹ����ѱ�Ϊ'�����')
void heapify(vector<int>& arr, int index, int heapSize)
{   // heapSize�����ŶѵĴ�С
    int left = index * 2 + 1; // ���ӵ��±�
    while (left < heapSize)  // �·����к���ʱ
    { 
        // ���������У�˭��ֵ�󣬰��±��largest
        int largest = left + 1 < heapSize && arr[left + 1] > arr[left] ? left + 1 : left;
        // ���ͺ���֮�䣬˭��ֵ�󣬰��±��largest
        largest = arr[largest] > arr[index] ? largest : index;
        if(largest == index) break;           
        swap(arr,largest,index);
        index = largest; // index������
        left = index * 2 + 1;
    }
}


void swap(vector<int>& arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}






