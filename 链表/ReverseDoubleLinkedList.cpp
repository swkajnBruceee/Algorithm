// ˫����ķ�ת
#include<iostream>
using namespace std;

// ˫����
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
    cout<<"��תǰ������";
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;


    node = reverseDoubleLinkedList(node);

    cout<<"��ת�������";
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}



