/*
正数数组costs,profits,正整数：k,m
costs［i］表示i号项目的花费，profits［i］表示i号项目在扣除花费之后还能挣到的钱（利润）
k表示你只能串行的最多做k个项目，m表示你初始的资金说明：
你每做完一个项目，马上获得的收益，可以支持你去做下一个项目。
输出你最后获得的最大钱数。
*/
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        
        // 定义节点结构体
        struct Node 
        {
            int p;  // 利润
            int c;  // 成本
            Node(int x, int y) : p(x), c(y) {}
        };
    
        // 比较器：成本小的节点排在前面（用于小根堆）
        struct MinCostComparator 
        {
            bool operator()(const Node& a, const Node& b) 
            {
                return a.c > b.c;
            }
        };
    
        // 比较器：利润大的节点排在前面（用于大根堆）
        struct MaxProfitComparator 
        {
            bool operator()(const Node& a, const Node& b) 
            {
                return a.p < b.p;
            }
        };
        
        
        int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
        {
            priority_queue<Node, vector<Node>, MinCostComparator> minCostQ;
            priority_queue<Node, vector<Node>, MaxProfitComparator> maxProfitQ;
    
            // 将所有项目放入成本小根堆中
            for (int i = 0; i < (int)profits.size(); i++) 
            {
                minCostQ.push(Node(profits[i], capital[i]));
            }
    
            for (int i = 0; i < k; i++) 
            {  
                // 进行 K 轮,将能力所及的项目放入利润大根堆中
                while (!minCostQ.empty() && minCostQ.top().c <= w) 
                {
                    maxProfitQ.push(minCostQ.top());
                    minCostQ.pop();
                }
    
                if (maxProfitQ.empty()) return w;
                w += maxProfitQ.top().p;
                maxProfitQ.pop();
            }
    
            return w;
        }
    };


