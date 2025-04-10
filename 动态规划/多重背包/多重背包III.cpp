/*  本题考查多重背包的单调队列优化方法
    0< N ≤1000
    0< V ≤20000
    0< v[i],w[i],s[i] ≤20000
*/

/*
1.状态转移方程：
    dp[j] =  max(    dp[j-k*v[i]] + k*w[i]     )
            0≤k≤s[i]
2.单调队列优化思想:
(1)分组处理：将容量 j 按 v[i] 的余数 r=j % v[i]分组，每组独立处理。
(2)窗口维护：对于每组余数 r，将 j 表示为 r+m*v[i]，
            状态转移转化为在窗口 m′∈[ m?s[i], m]内找到最大的 dp[r+m′*v[i]]?m′*w[i]，
            再通过公式转换得到当前最大值。
3.实现步骤：
(1)初始化：使用两个数组 prev_dp 和 curr_dp，分别表示上一轮和当前轮的状态。
           初始化 prev_dp 为前 i?1 个物品处理后的最优值。
(2) 遍历每个物品：
    复制状态：将 prev_dp 复制到 curr_dp。
    按余数分组：遍历余数 r∈[0,v[i]?1]。
    维护单调队列：对每个余数 r，遍历 m 使得 j=r+m*v[i] ≤ V。
3) 窗口操作:
    移除过期元素：从队列头部移除 m′ < m?s[i] 的元素。
    计算当前最大值：队列头部即为窗口内最大值，更新 curr_dp[j]。
    维护单调性：将当前 m 对应的值加入队列尾部，保持队列递减。
*/

#include <vector>
#include <deque>
using namespace std;

int multiKnapsack(int N, int V, vector<int>& v, vector<int>& w, vector<int>& s) {
    vector<int> prev_dp(V + 1, 0); // 初始状态：没有物品时，价值为0

    for (int i = 0; i < N; ++i) {
        vector<int> curr_dp = prev_dp; // 复制上一轮状态
        int vi = v[i], wi = w[i], si = s[i];

        for (int r = 0; r < vi; ++r) { // 按余数分组处理
            deque<int> q; // 单调队列，保存m'

            for (int m = 0; r + m * vi <= V; ++m) {
                int j = r + m * vi; // 当前容量

                // 移除窗口外的元素（m' < m - si）
                while (!q.empty() && q.front() < m - si) {
                    q.pop_front();
                }

                // 更新当前最大值
                if (!q.empty()) {
                    int k = q.front();
                    curr_dp[j] = max(curr_dp[j], prev_dp[r + k * vi] + (m - k) * wi);
                }

                // 维护队列单调性（递减）
                while (!q.empty() && (prev_dp[j] - m * wi) >= (prev_dp[r + q.back() * vi] - q.back() * wi)) {
                    q.pop_back();
                }
                q.push_back(m);
            }
        }

        prev_dp.swap(curr_dp); // 更新状态
    }

    return prev_dp[V];
}

