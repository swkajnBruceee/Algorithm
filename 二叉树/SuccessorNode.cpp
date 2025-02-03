// ���̽ڵ�(�������������)
#include<iostream>

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node* parent;
    Node(int x) : value(x), left(nullptr), right(nullptr), parent(nullptr){}
};


Node* getLeftMost(Node* node)
{
    while(node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}




Node* getSuccessorNode(Node* node)
{
    if(node == nullptr) return node;
    if(node->right != nullptr)
    {
        return getLeftMost(node->right);
    }
    else
    { // ��������
        Node* parent = node->parent;
        while(parent != nullptr && parent->left != node) // ��ǰ�ڵ����丸�׽ڵ���Һ���
        {
            node = parent;
            parent = node->parent;
        }
        return parent;
    }
}




int main()
{

    return 0;
}