// 方法二（优化为一维数组Dp） 
#include<iostream>
using namespace std;

int f[1001];    // f[i] = j 表示体积为 i 的时候最大价值是 j
int v[1001], w[1001];

int main()
{
    int N, V;
    cin>> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = V; j >= v[i]; j--) // 此时循环一定要从大到小
        {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }
    cout << f[V];
    return 0;
}