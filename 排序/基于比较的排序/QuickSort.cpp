// ��������
// ʱ�临�Ӷȣ�O(N*logN)
// ����ռ临�Ӷȣ�O(logN)
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;



// ����һ������arr[L...R]�ĺ���
// Ĭ����arr[R]�����֣�arr[R] �� ���p ������Ȼ��ֳ���������  <p   ==p   >p
//����ֵ��һ������Ϊ2������p��2�����ݷֱ��ʾ '==����' ����߽���ұ߽�
vector<int> partition(vector<int>& vec, int L, int R)
{
    int less = L - 1;  // '<��'�ұ߽�
    int more = R;      // '>��'��߽�
    while(L < more)    // L��ʾ��ǰλ��
    {
        if(vec[L] < vec[R])  // ��ǰ�� < ����ֵ
        {
            swap(vec[++less],vec[L++]); // �˴�Ҫע��
        }
        else if(vec[L] > vec[R])  // ��ǰ�� > ����ֵ
        {
            swap(vec[--more], vec[L]);
        }
        else
        {
            L++;
        }
    }
    swap(vec[more], vec[R]);
    vector<int> p = {less+1,more};
    return p;
}



    // arr[L...R]�ź���

void quickSort(vector<int>& vec,int L,int R)
{
    if(L < R)
    {
        swap(vec[L + rand()%(R-L+1)], vec[R]);  // �ȸ������ѡһ����������������λ�õ�������
        vector<int> p = partition(vec,L,R);  // ���ص�����p����һ��Ϊ2����ʾ'����ֵ'�����������߽���ұ߽� 
        quickSort(vec,L,p[0]-1);  // p[0]-1 Ϊ'<��'���ұ߽�
        quickSort(vec,p[1]+1,R);  // p[1]+1 Ϊ'>��'����߽�
    }
}


void quickSort(vector<int>& vec)
{
    if(vec.size() <2)
    {
        return;
    }
    quickSort(vec,0,vec.size()-1);
}



int main()
{
    srand(time(nullptr));  // ��ʼ���������

    vector<int> vec = {10, 7, 2, 9, 1, 5, 3, 2, 4, 5};
    quickSort(vec, 0, vec.size() - 1);
    cout << "���������飺"; 
    for(int r : vec)
    {
        cout << r << " ";
    }
    return 0;
}


