/*  本题考查多重背包的二进制优化方法
    0< N ≤1000
    0< V ≤2000
    0< v[i],w[i],s[i] ≤2000
*/
/*
解题方法：
        若一个商品有较大数 S 件，直接将其拆解成S个1件复杂度较高，
        可以考虑将其拆解成 n 个不重复的数字，这 n 个数字可以通过相加
        凑出 0~S 中任一数字,那么这件商品选择的数量就等价于，
        这 n 份选或不选，即为0-1背包问题
拆解方法：
        若有一较大数 S ，其可拆解成 n 个数
        n = log(S) (以二为底，且向上取整)
        设 m = S - 1 - 2 - 4 - 8 - ... - 2^k ≥ 0 ，
        则这 n 个数等于： 1, ... , 2^k , m 
*/
#include<iostream>
#include<vector>
using namespace std;
struct Good
{
    int v;  // 商品体积
    int w;  // 商品价值
};

int f[2001];
int main()
{
    vector<Good> goods;
    int N, V;
    cin >> N >> V;
    for(int i = 1; i <= N; i++)
    {
        int v, w, s;
        cin >> v >> w >> s;
        for(int k = 1; k <= s; k *= 2)
        {
            s -= k; // 第 i 次循环得出 n 个数中的第 i 个数
            goods.push_back({v * k, w * k}); // 然后将其看作一个新的商品加入商品列表中         
        }
        if(s > 0) goods.push_back({v * s, w * s}); // 最后一个也要加入其中
    }
    
    // 下面按照0-1背包问题解即可
    for(auto good : goods)
    {
        for(int j = V; j >= good.v; j--)
        {
            f[j] = max(f[j], f[j - good.v] + good.w);
        }
    }
    cout<<f[V]<<endl;
    return 0;
}
