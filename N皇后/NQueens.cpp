/*
N�ʺ�������ָ��N*N��������Ҫ��N���ʺ�Ҫ���κ������ʺ�ͬ�С���ͬ�У�Ҳ����ͬһ��б���ϡ�
����һ������n������n�ʺ�İڷ��ж����֡�
*/

#include<iostream>
#include<vector>
using namespace std;

int num(int n);
int process(int i, vector<int> record, int n);
bool isValid(vector<int> record, int i, int j);

int main()
{
    cout<<num(8);
    return 0;
}


int num(int n)
{
    if(n < 1) return 0;
    // record[i]=j ��ʾi�еĻʺ�����˵�j��(��������ʡȥ���ö�ά��������ʾ)
    vector<int> record(n);
    return process(0, record, n);
}

// Ŀǰ�����˵�i��(�ܹ���n��)
// record[0...i-1]��ʾ֮ǰ���з��˻ʺ�(Ǳ̨�ʣ�ǰi-1���κ������ʺ󶼲����С��С�б��)
// ����ֵ����������еĻʺ󣬺Ϸ��İڷ����ж�����
int process(int i, vector<int> record, int n)
{
    if(i == n) return 1;  // ������ֹ��
    int res = 0;
    for(int j = 0; j < n; j++) // ��ǰ����i�У���Ҫ����i�����е��� -> j
    {
        // ��ǰi�еĻʺ󣬷���j�У��᲻���֮ǰ(0...i-1)�Ļʺ��й��й�б��
        // ����ǣ���Ϊ��Ч��������ǣ���Ϊ��Ч
        if(isValid(record, i, j))
        {
            record[i] = j;
            res += process(i + 1, record, n);
        }
    }
    return res;
}


bool isValid(vector<int> record, int i, int j)
{
    for(int k = 0; k < i; k++)
    {
        if( j == record[k] || abs(record[k]-j) == i-k) return false;
        //    ^ ���� ^                 ^ ��б�� ^
    }
    return true;
}

