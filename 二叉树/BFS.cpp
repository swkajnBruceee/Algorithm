// 宽度、广度优先搜索(对于二叉树，实质上就是层序遍历)
#include<iostream>
#include<queue>
using namespace std;

struct treeNode
{
    int value;
    treeNode* left;
    treeNode* right;
    treeNode(int x) : value(x),left(nullptr),right(nullptr){}
};

void BFS(treeNode* head)
{
    if(head == nullptr) return;
    queue<treeNode*> que;
    que.push(head);
    while(!que.empty())
    {
        treeNode* cur = que.front();
        que.pop();
        cout<<cur->value<<" ";
        if(cur->left != nullptr)
        {
            que.push(cur->left);
        }
        if(cur->right != nullptr)
        {
            que.push(cur->right);
        }
    }
}


int main()
{
    treeNode* root = new treeNode(5);
    root->left = new treeNode(3);
    root->right = new treeNode(8);
    root->left->left = new treeNode(2);
    root->left->right = new treeNode(4);
    root->left->left->left = new treeNode(1);
    root->right->left = new treeNode(7);
    root->right->left->left = new treeNode(6);
    root->right->right = new treeNode(10);
    root->right->right->left = new treeNode(9);
    root->right->right->right = new treeNode(11);

    cout<<"宽度优先搜索(BFS): ";
    BFS(root);

    return 0;
}








