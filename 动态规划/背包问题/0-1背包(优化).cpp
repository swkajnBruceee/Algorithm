// ���������Ż�Ϊһά����Dp�� 
#include<iostream>
using namespace std;

int f[1001];    // f[i] = j ��ʾ���Ϊ i ��ʱ������ֵ�� j
int v[1001], w[1001];

int main()
{
    int N, V;
    cin>> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = V; j >= v[i]; j--) // ��ʱѭ��һ��Ҫ�Ӵ�С
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];
    return 0;
}