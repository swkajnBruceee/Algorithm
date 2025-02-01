/*
【题目】给定两个可能有环也可能无环的单链表，头节点head1和head2。
       请实现一个函数，如果两个链表相交，请返回相交的第一个节点。
       如果不相交，返回null
【要求】如果两个链表长度之和为N，时间复杂度请达到O(N)，额外空间复杂度O(1)。
*/
#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node* next;
    Node(int x) : value(x), next(nullptr){}
};

/************************************noLoop*******************************************/

// 如果两个链表都无环，返回相交的第一个节点，如果不相交，返回nullptr
Node* noLoop(Node* head1, Node* head2)
{
    if(head1 == nullptr || head2 == nullptr)
    {
        return nullptr;
    }
    Node* cur1 = head1;
    Node* cur2 = head2;
    int n = 0;
    while(cur1 != nullptr)
    {
        n++;
        cur1 = cur1->next;
    }
    while(cur2 != nullptr)
    {
        n--;
        cur2 = cur2->next;
    }
    if(cur1 != cur2)     // 若两个链表相交，那么从相交的第一个节点之后两个链表共用一条链
    {                    // 如果最后cur1 != cur2，就说明两个链表没有相交
        return nullptr;  // 没有相交就返回nullptr
    }

    // n : 链表1长度 - 链表2长度
    cur1 = n > 0 ? head1 : head2;         // 谁长，谁的头变成cur1 
    cur2 = cur1 == head1 ? head2 : head1; // 谁短，谁的头变成cur2
    n = abs(n);
    while(n != 0)
    {
        n--;
        cur1 = cur1->next;  // 长的先走，走的步数等于长链表比短链表多的长度
    }
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

/************************************BothLoop*******************************************/

// 如果两个链表都有环，返回相交的第一个节点，如果不相交，返回nullptr
Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)
{
    Node* cur1 = nullptr;
    Node* cur2 = nullptr;
    if(loop1 == loop2)  // 共用一个环，且入环节点相同
    {
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while(cur1 != loop1)
        {
            n++;
            cur1 = cur1->next;
        }
        while(cur2 != loop2)
        {
            n--;
            cur2 = cur2->next;
        }
        
        cur1 = n > 0 ? head1 : head2;         
        cur2 = cur1 == head1 ? head2 : head1; 
        n = abs(n);
        while(n != 0)
        {
            n--;
            cur1 = cur1->next;  
        }
        while(cur1 != cur2)
        {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }
    else  // 共用一个环，但入环节点不同
    {
        cur1 = loop1->next;
        while(cur1 != loop1) // 转回自己之前
        {
            if(cur1 == loop2)
            {
                return loop1; // return loop2 也可以，都叫第一个相交的节点
            }
            cur1 = cur1->next;
        }
        return nullptr;
    }
    
}





// 找到链表的第一个入环节点，如果无环，返回nullptr
Node* getLoopNode(Node* head)
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
        return nullptr;
    }
    Node* n1 = head->next;       // 慢指针 
    Node* n2 = head->next->next; // 快指针
    while(n1 != n2)
    {
        if(n2->next == nullptr || n2->next->next == nullptr)  // n1与n2无法相交
        {
            return nullptr;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    // n1,n2相遇后，n2(快指针)从头开始走，且改为一次走一步
    n2 = head; 
    while(n1 != n2)
    {
        n1 = n1->next;
        n2 = n2->next;
    }
    // 再次相遇时，就是第一个入环节点
    return n1;
}



Node* getIntersectNode(Node* head1, Node* head2)
{
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node* loop1 = getLoopNode(head1);
    Node* loop2 = getLoopNode(head2);
    // case 1:均无环
    if(loop1 == nullptr && loop2 == nullptr)
    {
        return noLoop(head1, head2);
    }
    // case 2:均有环 
    if(loop1 != nullptr && loop2 != nullptr)
    {
        return bothLoop(head1, loop1, head2, loop2);
    }
    // case 3:一个有环和一个无环的链表不可能相交，所以此种情况不成立
    return nullptr;
}

int main()
{
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node* commonNode = head1->next->next;

    commonNode->next = new Node(4);
    commonNode->next->next = new Node(5);
    commonNode->next->next->next = new Node(6);
    commonNode->next->next->next->next = commonNode;
    
    Node* head2 = new Node(9);
    head2->next = new Node(8);
    head2->next->next = new Node(7);
    head2->next->next->next = commonNode;
    
    Node* intersect = getIntersectNode(head1, head2);

    if(intersect != nullptr)
    {
        cout<<"Intersected at node with value:"<<intersect->value<<endl;
    }
    else
    {
        cout<<"No intersection"<<endl;
    }

    return 0;
}














