// 二叉树的序列化和反序列化
#include<iostream>
#include<string>
using namespace std;


struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr){}
};



string serial_By_Pre(Node* head)
{
    if(head == nullptr) return "#_";
    string res = to_string(head->value) + "_";
    res += serial_By_Pre(head->left);
    res += serial_By_Pre(head->right);
    return res;
}



int main()
{
    Node* head = new Node(1);
    head->right = new Node(1);
    head->right->left = new Node(1);
    head->right->left->right = new Node(1);
    cout<<serial_By_Pre(head)<<endl;
    return 0;
}









