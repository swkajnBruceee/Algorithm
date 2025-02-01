// 双链表的反转
#include<iostream>
using namespace std;

// 双链表
struct DoubleNode
{
    int value;
    DoubleNode* last;
    DoubleNode* next;
    DoubleNode() : value(0), last(nullptr), next(nullptr){};
    DoubleNode(int x) : value(x), last(nullptr), next(nullptr){};
};

DoubleNode* reverseDoubleLinkedList(DoubleNode* head)
{
    DoubleNode* pre = nullptr; 
    DoubleNode* next = nullptr;
    while(head != nullptr)
    {
        next = head->next;
        head->next = pre;
        head->last = next;
        pre = head;
        head = next;
    } 
    return pre;
}





int main()
{
    DoubleNode* node = new DoubleNode(1);
    node->next = new DoubleNode(2);
    node->next->next = new DoubleNode(3);
    node->next->next->next = new DoubleNode(4);

    DoubleNode* head = node;
    cout<<"反转前的链表：";
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;


    node = reverseDoubleLinkedList(node);

    cout<<"反转后的链表：";
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}



