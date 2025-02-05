#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;          // ͼ�Ķ�������
    vector<vector<int>> adjList; // �ڽӱ�

public:
    // ���캯������ʼ�������������������ڽӱ�
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    // �������ͼ�ıߣ�˫��
    void AddEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // ��Ϊ����ͼ��ע�ʹ���
    }

    // ���������������
    vector<int> BFS(int startVertex) {
        vector<bool> visited(numVertices, false); // ��¼����״̬
        queue<int> q;           // BFS����
        vector<int> bfsOrder;   // �洢����˳��

        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            bfsOrder.push_back(current); // ����ǰ�ڵ�������˳��

            // ������ǰ�ڵ�������ڽӵ�
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
    // ����һ������5�������ͼ
    Graph g(5);

    // ���ͼ�ıߣ�����ͼ��
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 3);
    g.AddEdge(2, 4);
    g.AddEdge(3, 4);

    // �Ӷ���0��ʼִ��BFS
    vector<int> bfsResult = g.BFS(0);

    // ����������
    cout << "BFS����˳��: ";
    for (int node : bfsResult) {
        cout << node << " ";
    }

    return 0;
}