#include<iostream>
#include<queue>
#include<unordered_set>
#include "Graph.cpp"
#include "GraphGenerator.cpp"



void bfs(Node* node)
{
    if(node == nullptr) return;
    queue<Node*> que;
    unordered_set<Node*> set;
    que.push(node);
    set.emplace(node);
    while(!que.empty())
    {
        Node* cur = que.front();
        que.pop();
        cout<<cur->value<<endl;
        for(Node* next : cur->nexts)
        {
            if(set.find(next) == set.end())  // set中不含next
            {
                set.emplace(next);
                que.push(next);
            }
        }
    }
}



int main() {
    // 假设我们有一个简单的 3x3 矩阵表示图的边
    int matrix[3][3] = {
        {1, 2, 1},
        {2, 3, 1},
        {1, 3, 2}
    };

    // 将矩阵转换为二维指针
    int** matrixPtr = new int*[3];
    for (int i = 0; i < 3; i++) {
        matrixPtr[i] = matrix[i];
    }

    Graph graph = createGraph(matrixPtr, 3);

    // // 释放动态分配的内存
    // delete[] matrixPtr;

    return 0;
}





