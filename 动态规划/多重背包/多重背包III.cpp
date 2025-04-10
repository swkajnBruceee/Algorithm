/*  ���⿼����ر����ĵ��������Ż�����
    0< N ��1000
    0< V ��20000
    0< v[i],w[i],s[i] ��20000
*/

/*
1.״̬ת�Ʒ��̣�
    dp[j] =  max(    dp[j-k*v[i]] + k*w[i]     )
            0��k��s[i]
2.���������Ż�˼��:
(1)���鴦�������� j �� v[i] ������ r=j % v[i]���飬ÿ���������
(2)����ά��������ÿ������ r���� j ��ʾΪ r+m*v[i]��
            ״̬ת��ת��Ϊ�ڴ��� m���[ m?s[i], m]���ҵ����� dp[r+m��*v[i]]?m��*w[i]��
            ��ͨ����ʽת���õ���ǰ���ֵ��
3.ʵ�ֲ��裺
(1)��ʼ����ʹ���������� prev_dp �� curr_dp���ֱ��ʾ��һ�ֺ͵�ǰ�ֵ�״̬��
           ��ʼ�� prev_dp Ϊǰ i?1 ����Ʒ����������ֵ��
(2) ����ÿ����Ʒ��
    ����״̬���� prev_dp ���Ƶ� curr_dp��
    ���������飺�������� r��[0,v[i]?1]��
    ά���������У���ÿ������ r������ m ʹ�� j=r+m*v[i] �� V��
3) ���ڲ���:
    �Ƴ�����Ԫ�أ��Ӷ���ͷ���Ƴ� m�� < m?s[i] ��Ԫ�ء�
    ���㵱ǰ���ֵ������ͷ����Ϊ���������ֵ������ curr_dp[j]��
    ά�������ԣ�����ǰ m ��Ӧ��ֵ�������β�������ֶ��еݼ���
*/

#include <vector>
#include <deque>
using namespace std;

int multiKnapsack(int N, int V, vector<int>& v, vector<int>& w, vector<int>& s) {
    vector<int> prev_dp(V + 1, 0); // ��ʼ״̬��û����Ʒʱ����ֵΪ0

    for (int i = 0; i < N; ++i) {
        vector<int> curr_dp = prev_dp; // ������һ��״̬
        int vi = v[i], wi = w[i], si = s[i];

        for (int r = 0; r < vi; ++r) { // ���������鴦��
            deque<int> q; // �������У�����m'

            for (int m = 0; r + m * vi <= V; ++m) {
                int j = r + m * vi; // ��ǰ����

                // �Ƴ��������Ԫ�أ�m' < m - si��
                while (!q.empty() && q.front() < m - si) {
                    q.pop_front();
                }

                // ���µ�ǰ���ֵ
                if (!q.empty()) {
                    int k = q.front();
                    curr_dp[j] = max(curr_dp[j], prev_dp[r + k * vi] + (m - k) * wi);
                }

                // ά�����е����ԣ��ݼ���
                while (!q.empty() && (prev_dp[j] - m * wi) >= (prev_dp[r + q.back() * vi] - q.back() * wi)) {
                    q.pop_back();
                }
                q.push_back(m);
            }
        }

        prev_dp.swap(curr_dp); // ����״̬
    }

    return prev_dp[V];
}

