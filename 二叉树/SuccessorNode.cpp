// 求后继节点(与中序遍历类似)
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
    { // 无右子树
        Node* parent = node->parent;
        while(parent != nullptr && parent->left != node) // 当前节点是其父亲节点的右孩子
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