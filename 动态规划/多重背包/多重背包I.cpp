/*
第 i 种物品最多有s[i]件，每件体积是v[i]，价值是w[i]
0< N,V ≤100
0< v[i],w[i],s[i] ≤100
*/

// 多重背包是0-1背包的扩展问题,所以只需延续其思路再多加一重循环即可
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