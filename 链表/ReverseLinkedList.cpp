// ������ķ�ת
#include<iostream>
using namespace std;

// ������
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

    // ��¼ͷ�ڵ�
    Node* head = node;

    cout<<"��תǰ������";
    while(head != nullptr)
    {
        cout<<head->value<<" ";
        head = head->next;
    }
    cout<<endl;

    // ��ת����
    node = reverseLinkedList(node);

    cout<<"��ת�������";
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}



