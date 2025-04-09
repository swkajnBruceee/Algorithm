#include<iostream>
using namespace std;

// 方法二(优化后)
int f[1001];
int v[1001], w[1001];
int main()
{
    int N, V;
    cin>> N >> V;
    for(int i = 1; i <= N; i++) cin>> v[i] >> w[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            f[j] = f[j];
            if(j >= v[i])
            {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }
    cout<<f[V];
    return 0;
}