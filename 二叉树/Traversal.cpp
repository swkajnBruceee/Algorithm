// 二叉树-遍历（与递归序有关）
#include<iostream>
#include<stack>
using namespace std;

struct treeNode
{
    int value;
    treeNode* left;
    treeNode* right;
    treeNode(int x) : value(x),left(nullptr),right(nullptr){}
};


// 完成遍历操作的样板
void f(treeNode* root)
{
    if(root == nullptr) return;
    f(root->left);
    f(root->right);
}

// 先序遍历（头、左、右）- 递归
void preOrderRecur(treeNode* root)
{
    if(root == nullptr) return;
    cout<<root->value<<" ";
    preOrderRecur(root->left);
    preOrderRecur(root->right);

}
// 中序遍历（左、头、右）- 递归
void inOrderRecur(treeNode* root)
{
    if(root == nullptr) return;   
    inOrderRecur(root->left);
    cout<<root->value<<" ";
    inOrderRecur(root->right);

}
// 后序遍历（左、右、头）- 递归
void posOrderRecur(treeNode* root)
{
    if(root == nullptr) return;   
    posOrderRecur(root->left);
    posOrderRecur(root->right);
    cout<<root->value<<" ";
}

/*************************************************************/

// 先序遍历（头、左、右）- 非递归
void preOrderUnRecur(treeNode* head)
{
    if(head != nullptr)
    {
        stack<treeNode*> mystack;
        mystack.push(head);
        while(!mystack.empty())
        {
            head = mystack.top();
            mystack.pop();
            cout<<head->value<<" ";
            if(head->right != nullptr)
            {
                mystack.push(head->right);
            }
            if(head->left != nullptr)
            {
                mystack.push(head->left);
            }
        }
    }
}

// 中序遍历（左、头、右）- 非递归
void inOrderUnRecur(treeNode* head)
{
    if(head != nullptr)
    {
        stack<treeNode*> mystack;
        while(!mystack.empty() || head != nullptr)
        {
            if(head != nullptr)
            {
                mystack.push(head);
                head = head->left;
            }
            else
            {
                head = mystack.top();
                mystack.pop();
                cout<<head->value<<" ";
                head = head->right;
            }
        }
    }   
}



// 后序遍历（左、右、头）- 非递归
void posOrderUnRecur(treeNode* head)
{
    if(head != nullptr)
    {
        stack<treeNode*> s1;
        stack<treeNode*> s2;
        s1.push(head);
        while(!s1.empty())
        {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if(head->left != nullptr)
            {
                s1.push(head->left);
            }
            if(head->right != nullptr)
            {
                s1.push(head->right);
            }
        }
        while(!s2.empty())
        {
            cout<<s2.top()->value<<" ";
            s2.pop();
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

    cout<<"先序遍历： ";preOrderRecur(root);cout<<endl;
    cout<<"中序遍历： ";inOrderRecur(root);cout<<endl;
    cout<<"后序遍历： ";posOrderRecur(root);cout<<endl;

    cout<<"pre-order-unrecur: ";preOrderUnRecur(root);cout<<endl;
    cout<<"in-order-unrecur: ";inOrderUnRecur(root);cout<<endl;
    cout<<"pos-order-unrecur: ";posOrderUnRecur(root);cout<<endl;

    return 0;
}







