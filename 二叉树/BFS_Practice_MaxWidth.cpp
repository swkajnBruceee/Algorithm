// 求一棵二叉树的最大宽度
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct treeNode
{
    int value;
    treeNode* left;
    treeNode* right;
    treeNode(int x) : value(x),left(nullptr),right(nullptr){}
};

int maxWidth(treeNode* head)
{
    if(head == nullptr) return 0;
    queue<treeNode*> que;
    que.push(head);
    int max_width = 0;
    while(!que.empty())
    {
        int current_size = que.size();
        max_width = max(max_width, current_size); // 更新最大宽度
        for(int i = 0; i < current_size;i++)
        {
            treeNode* cur = que.front();
            que.pop();
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
    return max_width;
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

    cout<<"二叉树的最大宽度为："<<maxWidth(root);


    return 0;
}








