// 复制含有随机指针节点的链表
//要求：时间复杂度O(N)  额外空间复杂度O(1) 
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

// 创建含随机指针的单链表
Node* creatRandomList(int n)
{
    if(n <= 0) return nullptr;

    vector<Node*> nodes; 
    Node* head = new Node(1);
    nodes.push_back(head);

    // 创建基础链表结构
    Node* cur = head;
    for(int i = 2; i <= n; i++)
    {
        cur->next = new Node(i);
        cur = cur->next;
        nodes.push_back(cur);
    }

    // 设置随机指针
    srand(time(0));  // 初始化随机种子
    for(auto node : nodes)
    {
        int rand_index = rand() % (n + 1); // 0~n-1为有效索引，n表示nullptr
        node->rand = (rand_index == n) ? nullptr : nodes[rand_index];
    }
    return head;
}

// 释放链表内存
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}


// ********开始复制********



// 方法1：哈希表

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
        // cur 老
        // map[cur] 新
        map[cur]->next = map[cur->next];
        map[cur]->rand = map[cur->rand];
        cur = cur->next;
    }
    return map[head];
}

// 方法2：克隆出新节点直接连接在老节点后
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
    // copy节点的rand指针
    while(cur != nullptr)
    {
        // 一对一对遍历
        next = cur->next->next;
        curCopy = cur->next;
        curCopy->rand = cur->rand != nullptr ? cur->rand->next : nullptr;  // cur.rand.next为cur.rand的克隆节点
        cur = next;
    }
    Node* result = head->next;
    cur = head;
    // 将原链表和克隆链表分离
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









