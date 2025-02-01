// 判断链表是否回文(快慢指针法)
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
    Node* n1 = head; // 慢指针
    Node* n2 = head; // 快指针
    while(n2->next != nullptr && n2->next->next != nullptr)
    {
        n1 = n1->next;  // n1 -> mid
        n2 = n2->next->next;  // n2 -> end
    }
    // 当跳出while循环时，代表n2(快指针)走到结尾，此时n1(慢指针)走到中点！

    Node* n3 = n1; // 记录左半部分的最后位置，方便判断完成后连接上右半部分
    n2 = n1->next; // 记录一下中点下一个位置（右半部分的初始位置）   
    n1->next = nullptr;

    n2 = reverseLinkedList(n2); // 反转右半部分

    Node* n4 = n2; // 记录反转后右半部分的初始位置，方便判断完成后再把右半部分反转回来
    n1 = head; // 左半部分从头开始

    bool result = true;
    while(n1 != nullptr && n2 != nullptr)
    {
        if(n1->value != n2->value)
        {
            result = false;
            break;
        }
        n1 = n1->next;  // left  to mid(左半部分遍历)
        n2 = n2->next;  // right to mid(右半部分遍历)
    }

    // 判断完成后不要忘记再把右半部分反转回来
    n4 = reverseLinkedList(n4);

    //判断完成后连接上右半部分
    n3->next = n4;

    return result;


}




int main()
{
    Node* node = new Node(1);
    node->next = new Node(2);
    node->next->next = new Node(3);
    node->next->next->next = new Node(4);

    cout<< boolalpha << isPalindrome(node) << endl;  //  boolalpha是为了使输出结果是true/false，而不是默认的 1/0
    
    while(node != nullptr)
    {
        cout<<node->value<<" ";
        node = node->next;
    }

    return 0;
}




