/*
�� i ����Ʒ�����s[i]����ÿ�������v[i]����ֵ��w[i]
0< N,V ��100
0< v[i],w[i],s[i] ��100
*/

// ���ر�����0-1��������չ����,����ֻ��������˼·�ٶ��һ��ѭ������
#include<iostream>
using namespace std;

int f[101];
int v[101], w[101], s[101];
int main()
{
    int N, V;
    cin >> N >> V ;
    for(int i = 1; i <= N; i++) cin>> v[i] >> w[i] >> s[i];

    for(int i = 1; i <= N; i++)
    {
        for(int j = V; j >= 0; j--)
        {
            for(int k = 1; k <= s[i] && j >= k*v[i]; k++)
            {
                f[j] = max(f[j], f[j - k*v[i]] + k*w[i]);
            }
        }
    }
    cout<<f[V];
    return 0;
}