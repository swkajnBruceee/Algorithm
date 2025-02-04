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
            if(set.find(next) == set.end())  // set�в���next
            {
                set.emplace(next);
                que.push(next);
            }
        }
    }
}



int main() {
    // ����������һ���򵥵� 3x3 �����ʾͼ�ı�
    int matrix[3][3] = {
        {1, 2, 1},
        {2, 3, 1},
        {1, 3, 2}
    };

    // ������ת��Ϊ��άָ��
    int** matrixPtr = new int*[3];
    for (int i = 0; i < 3; i++) {
        matrixPtr[i] = matrix[i];
    }

    Graph graph = createGraph(matrixPtr, 3);

    // // �ͷŶ�̬������ڴ�
    // delete[] matrixPtr;

    return 0;
}





