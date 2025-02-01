// 单链表的反转
#include<iostream>
using namespace std;

// 单链表
struct Node
{
    int value;
    Node* next;
    Node() : value(0), next(nullptr){};
    Node(int x) : value(x), next(nullptr){};
};

Node* reverseLinkedList(Node* head)
{
    Node* pre = nullptr; 
    Node* next = nullptr;
    while(head != nullptr)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    } 
    return pre;
}





int main()
{
    Node* node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);

    // 记录头节点
    Node* head = node;

    cout<<"反转前的链表：";
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;

    // 反转链表
    node = reverseLinkedList(node);

    cout<<"反转后的链表：";
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}



