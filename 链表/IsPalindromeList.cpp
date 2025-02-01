// �ж������Ƿ����(����ָ�뷨)
#include<iostream>
using namespace std;


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


bool isPalindrome(Node* head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return true;
    }
    Node* n1 = head; // ��ָ��
    Node* n2 = head; // ��ָ��
    while(n2->next != nullptr && n2->next->next != nullptr)
    {
        n1 = n1->next;  // n1 -> mid
        n2 = n2->next->next;  // n2 -> end
    }
    // ������whileѭ��ʱ������n2(��ָ��)�ߵ���β����ʱn1(��ָ��)�ߵ��е㣡

    Node* n3 = n1; // ��¼��벿�ֵ����λ�ã������ж���ɺ��������Ұ벿��
    n2 = n1->next; // ��¼һ���е���һ��λ�ã��Ұ벿�ֵĳ�ʼλ�ã�   
    n1->next = nullptr;

    n2 = reverseLinkedList(n2); // ��ת�Ұ벿��

    Node* n4 = n2; // ��¼��ת���Ұ벿�ֵĳ�ʼλ�ã������ж���ɺ��ٰ��Ұ벿�ַ�ת����
    n1 = head; // ��벿�ִ�ͷ��ʼ

    bool result = true;
    while(n1 != nullptr && n2 != nullptr)
    {
        if(n1->value != n2->value)
        {
            result = false;
            break;
        }
        n1 = n1->next;  // left  to mid(��벿�ֱ���)
        n2 = n2->next;  // right to mid(�Ұ벿�ֱ���)
    }

    // �ж���ɺ�Ҫ�����ٰ��Ұ벿�ַ�ת����
    n4 = reverseLinkedList(n4);

    //�ж���ɺ��������Ұ벿��
    n3->next = n4;

    return result;


}




int main()
{
    Node* node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);

    cout<< boolalpha << isPalindrome(node) << endl;  //  boolalpha��Ϊ��ʹ��������true/false��������Ĭ�ϵ� 1/0
    
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}




