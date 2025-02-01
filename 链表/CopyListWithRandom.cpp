// ���ƺ������ָ��ڵ������
//Ҫ��ʱ�临�Ӷ�O(N)  ����ռ临�Ӷ�O(1) 
#include<iostream>
#include<unordered_map>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;


struct Node
{
    int value;
    Node* next;
    Node* rand;
    Node(int x) : value(x), next(nullptr), rand(nullptr){}
    
};

// ���������ָ��ĵ�����
Node* creatRandomList(int n)
{
    if(n <= 0) return nullptr;

    vector<Node*> nodes; 
    Node* head = new Node(1);
    nodes.push_back(head);

    // ������������ṹ
    Node* cur = head;
    for(int i = 2; i <= n; i++)
    {
        cur->next = new Node(i);
        cur = cur->next;
        nodes.push_back(cur);
    }

    // �������ָ��
    srand(time(0));  // ��ʼ���������
    for(auto node : nodes)
    {
        int rand_index = rand() % (n + 1); // 0~n-1Ϊ��Ч������n��ʾnullptr
        node->rand = (rand_index == n) ? nullptr : nodes[rand_index];
    }
    return head;
}

// �ͷ������ڴ�
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


// ********��ʼ����********



// ����1����ϣ��

Node* copyListWithRand1(Node* head)
{
    if(head == nullptr) return nullptr;
    unordered_map<Node*,Node*> map;
    Node* cur = head;
    while(cur != nullptr)
    {
        map.emplace(cur,new Node(cur->value));
    }
    cur = head;
    while(cur != nullptr)
    {
        // cur ��
        // map[cur] ��
        map[cur]->next = map[cur->next];
        map[cur]->rand = map[cur->rand];
        cur = cur->next;
    }
    return map[head];
}

// ����2����¡���½ڵ�ֱ���������Ͻڵ��
Node* copyListWithRand2(Node* head)
{
    if(head == nullptr) return nullptr;
    Node* cur = head;
    Node* next =nullptr;
    // copy node and link to every node
    // 1 -> 2
    // 1 -> 1' -> 2 -> 2'
    while(cur != nullptr)
    {
        next = cur->next;
        cur->next = new Node(cur->value);
        cur->next->next = next;
        cur = next;
    }
    cur = head;
    Node* curCopy = nullptr;
    // copy�ڵ��randָ��
    while(cur != nullptr)
    {
        // һ��һ�Ա���
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != nullptr ? cur->rand->next : nullptr;  // cur.rand.nextΪcur.rand�Ŀ�¡�ڵ�
        cur = next;
    }
    Node* result = head->next;
    cur = head;
    // ��ԭ����Ϳ�¡�������
    while(cur != nullptr)
    {
        next = cur->next->next;
        curCopy = cur->next;
        cur->next = next;
        curCopy->next = next != nullptr ? next->next : nullptr;
        cur = next;
    }
    return result;
}


int main()
{

    return 0;
}









