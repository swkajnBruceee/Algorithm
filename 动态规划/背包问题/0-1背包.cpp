/*
有N件物品和一个容量是V的背包。每件物品只能使用一次。第i件物品的体积是v[i]，价值是w[i]。
求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。
接下来有N行，每行两个整数 v[i],w[i],用空格隔开，分别表示第i件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0 < N,V ≤ 1000
0 < v[i], w[i] ≤ 1000

*/

// 方法一（二维数组Dp）
#include<iostream>
using namespace std;

int f[1001][1001];    // f[i][j] = k 表示只看 i 件商品，总体积为 j 时，最大价值是 k 
int v[1001], w[1001];

int main()
{
    int N, V;
    f[0][0] = 0;
    cin >> N >> V;
    for(int i = 1; i <= N; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j <= V; j++)
        {
            // 不选第 i 个物品
            f[i][j] = f[i - 1][j];
            if(j >= v[i])
            {
                // 选第 i 个物品
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    int res = f[N][V];
    cout << res << endl;
    return 0;
}

