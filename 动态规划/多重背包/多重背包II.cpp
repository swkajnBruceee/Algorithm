/*  ���⿼����ر����Ķ������Ż�����
    0< N ��1000
    0< V ��2000
    0< v[i],w[i],s[i] ��2000
*/
/*
���ⷽ����
        ��һ����Ʒ�нϴ��� S ����ֱ�ӽ������S��1�����ӶȽϸߣ�
        ���Կ��ǽ������ n �����ظ������֣��� n �����ֿ���ͨ�����
        �ճ� 0~S ����һ����,��ô�����Ʒѡ��������͵ȼ��ڣ�
        �� n ��ѡ��ѡ����Ϊ0-1��������
��ⷽ����
        ����һ�ϴ��� S ����ɲ��� n ����
        n = log(S) (�Զ�Ϊ�ף�������ȡ��)
        �� m = S - 1 - 2 - 4 - 8 - ... - 2^k �� 0 ��
        ���� n �������ڣ� 1, ... , 2^k , m 
*/
#include<iostream>
#include<vector>
using namespace std;
struct Good
{
    int v;  // ��Ʒ���
    int w;  // ��Ʒ��ֵ
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
            s -= k; // �� i ��ѭ���ó� n �����еĵ� i ����
            goods.push_back({v * k, w * k}); // Ȼ���俴��һ���µ���Ʒ������Ʒ�б���         
        }
        if(s > 0) goods.push_back({v * s, w * s}); // ���һ��ҲҪ��������
    }
    
    // ���水��0-1��������⼴��
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
