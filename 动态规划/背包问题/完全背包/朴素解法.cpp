#include<iostream>
using namespace std;

int f[1001][1001];
int v[1001], w[1001];
int N, V;
int main()
{
    cin>> N >> V;
    for(int i = 1; i <= N; i++) cin>>v[i] >> w[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
            {
                f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]);
            }
        }
    }
    cout<<f[N][V];
    return 0;
}


