/*
��������costs,profits,��������k,m
costs��i�ݱ�ʾi����Ŀ�Ļ��ѣ�profits��i�ݱ�ʾi����Ŀ�ڿ۳�����֮����������Ǯ������
k��ʾ��ֻ�ܴ��е������k����Ŀ��m��ʾ���ʼ���ʽ�˵����
��ÿ����һ����Ŀ�����ϻ�õ����棬����֧����ȥ����һ����Ŀ��
���������õ����Ǯ����
*/
#include <iostream>
#include <queue>
using namespace std;

class Solution {
    public:
        
        // ����ڵ�ṹ��
        struct Node 
        {
            int p;  // ����
            int c;  // �ɱ�
            Node(int x, int y) : p(x), c(y) {}
        };
    
        // �Ƚ������ɱ�С�Ľڵ�����ǰ�棨����С���ѣ�
        struct MinCostComparator 
        {
            bool operator()(const Node& a, const Node& b) 
            {
                return a.c > b.c;
            }
        };
    
        // �Ƚ����������Ľڵ�����ǰ�棨���ڴ���ѣ�
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
    
            // ��������Ŀ����ɱ�С������
            for (int i = 0; i < (int)profits.size(); i++) 
            {
                minCostQ.push(Node(profits[i], capital[i]));
            }
    
            for (int i = 0; i < k; i++) 
            {  
                // ���� K ��,��������������Ŀ��������������
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


