/*
����Ŀ���������������л�Ҳ�����޻��ĵ�����ͷ�ڵ�head1��head2��
       ��ʵ��һ��������������������ཻ���뷵���ཻ�ĵ�һ���ڵ㡣
       ������ཻ������null
��Ҫ���������������֮��ΪN��ʱ�临�Ӷ���ﵽO(N)������ռ临�Ӷ�O(1)��
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

// ������������޻��������ཻ�ĵ�һ���ڵ㣬������ཻ������nullptr
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
    if(cur1 != cur2)     // �����������ཻ����ô���ཻ�ĵ�һ���ڵ�֮������������һ����
    {                    // ������cur1 != cur2����˵����������û���ཻ
        return nullptr;  // û���ཻ�ͷ���nullptr
    }

    // n : ����1���� - ����2����
    cur1 = n > 0 ? head1 : head2;         // ˭����˭��ͷ���cur1 
    cur2 = cur1 == head1 ? head2 : head1; // ˭�̣�˭��ͷ���cur2
    n = abs(n);
    while(n != 0)
    {
        n--;
        cur1 = cur1->next;  // �������ߣ��ߵĲ������ڳ�����ȶ������ĳ���
    }
    while(cur1 != cur2)
    {
        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    return cur1;
}

/************************************BothLoop*******************************************/

// ������������л��������ཻ�ĵ�һ���ڵ㣬������ཻ������nullptr
Node* bothLoop(Node* head1, Node* loop1, Node* head2, Node* loop2)
{
    Node* cur1 = nullptr;
    Node* cur2 = nullptr;
    if(loop1 == loop2)  // ����һ���������뻷�ڵ���ͬ
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
    else  // ����һ���������뻷�ڵ㲻ͬ
    {
        cur1 = loop1->next;
        while(cur1 != loop1) // ת���Լ�֮ǰ
        {
            if(cur1 == loop2)
            {
                return loop1; // return loop2 Ҳ���ԣ����е�һ���ཻ�Ľڵ�
            }
            cur1 = cur1->next;
        }
        return nullptr;
    }
    
}





// �ҵ�����ĵ�һ���뻷�ڵ㣬����޻�������nullptr
Node* getLoopNode(Node* head)
{
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
    {
        return nullptr;
    }
    Node* n1 = head->next;       // ��ָ�� 
    Node* n2 = head->next->next; // ��ָ��
    while(n1 != n2)
    {
        if(n2->next == nullptr || n2->next->next == nullptr)  // n1��n2�޷��ཻ
        {
            return nullptr;
        }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    // n1,n2������n2(��ָ��)��ͷ��ʼ�ߣ��Ҹ�Ϊһ����һ��
    n2 = head; 
    while(n1 != n2)
    {
        n1 = n1->next;
        n2 = n2->next;
    }
    // �ٴ�����ʱ�����ǵ�һ���뻷�ڵ�
    return n1;
}



Node* getIntersectNode(Node* head1, Node* head2)
{
    if(head1 == nullptr || head2 == nullptr) return nullptr;
    Node* loop1 = getLoopNode(head1);
    Node* loop2 = getLoopNode(head2);
    // case 1:���޻�
    if(loop1 == nullptr && loop2 == nullptr)
    {
        return noLoop(head1, head2);
    }
    // case 2:���л� 
    if(loop1 != nullptr && loop2 != nullptr)
    {
        return bothLoop(head1, loop1, head2, loop2);
    }
    // case 3:һ���л���һ���޻������������ཻ�����Դ������������
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














