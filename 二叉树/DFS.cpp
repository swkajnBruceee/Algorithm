// �����������(���ڶ�������ʵ���Ͼ����������)
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

// ���������ͷ�����ң�- �ݹ�
void preOrderRecur(treeNode* root)
{
    if(root == nullptr) return;
    cout<<root->value<<" ";
    preOrderRecur(root->left);
    preOrderRecur(root->right);

}

// ���������ͷ�����ң�- �ǵݹ�
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

    cout<<"�����������(DFS)1: ";preOrderRecur(root);cout<<endl;
    
    cout<<"�����������(DFS)2: ";preOrderUnRecur(root);cout<<endl;
   

    return 0;
}









