#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;          // 图的顶点数量
    vector<vector<int>> adjList; // 邻接表

public:
    // 构造函数：初始化顶点数量，并创建邻接表
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // 添加无向图的边（双向）
    void AddEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // 若为有向图则注释此行
    }

    // 广度优先搜索函数
    vector<int> BFS(int startVertex) {
        vector<bool> visited(numVertices, false); // 记录访问状态
        queue<int> q;           // BFS队列
        vector<int> bfsOrder;   // 存储遍历顺序

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            bfsOrder.push_back(current); // 将当前节点加入遍历顺序

            // 遍历当前节点的所有邻接点
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfsOrder;
    }
};

int main() {
    // 创建一个包含5个顶点的图
    Graph g(5);

    // 添加图的边（无向图）
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 4);
    g.AddEdge(3, 4);

    // 从顶点0开始执行BFS
    vector<int> bfsResult = g.BFS(0);

    // 输出遍历结果
    cout << "BFS遍历顺序: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }

    return 0;
}