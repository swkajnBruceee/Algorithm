/* 二叉树的序列化和反序列化
   (就是内存里的一棵树如何变成字符串形式，又如何从字符串形式变成内存里的树。
   可用于判断一棵二叉树是不是另一棵二叉树的子树)
*/
#include<iostream>
#include <vector>    // 向量容器
#include <queue>     // 队列容器
#include <string>    // 字符串操作
#include <sstream>   // 字符串流操作
using namespace std; // 使用标准命名空间

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node(int x) : value(x), left(nullptr), right(nullptr){}
};

string serial_By_Pre(Node* head);
Node* recon_By_PreString(string& preStr);
Node* reconPreOrder(queue<string>& q);
vector<string> split(string& s, char delimiter);




int main()
{
    Node* head1 = new Node(1);
    head1->right = new Node(1);
    head1->right->left = new Node(1);
    head1->right->left->right = new Node(1);
    cout<<serial_By_Pre(head1)<<endl;
    
    string prestr = "1_2_#_#_3_#_#";  
    Node* head2 = recon_By_PreString(prestr);
    cout<<head2->value<<" "<<head2->left->value<<" "<<head2->right->value;    
    return 0;
}






// 序列化(先序法)
string serial_By_Pre(Node* head)
{
    if(head == nullptr) return "#_";
    string res = to_string(head->value) + "_";
    res += serial_By_Pre(head->left);
    res += serial_By_Pre(head->right);
    return res;
}


// 反序列化(先序法)
Node* recon_By_PreString(string& preStr) 
{
    vector<string> values = split(preStr, '_'); // 分割字符串
    queue<string> q;                            // 创建队列
    for (const string& val : values) {          // 将分割结果存入队列
        q.push(val);
    }
    return reconPreOrder(q); // 调用递归函数构建树
}


Node* reconPreOrder(queue<string>& q) 
{
    string value = q.front(); // 获取队首元素
    q.pop();                  // 弹出队首元素（模拟Java的poll()）
    if (value == "#") {       // 终止条件：遇到空节点标记
        return nullptr;
    }
    Node* head = new Node(stoi(value)); // 创建新节点（字符串转整数）
    head->left = reconPreOrder(q);      // 递归构建左子树
    head->right = reconPreOrder(q);     // 递归构建右子树
    return head;
}

vector<string> split(string& s, char delimiter) 
{
    vector<string> tokens;        // 存储分割后的子字符串
    string token;                 // 临时存储每个子字符串
    istringstream tokenStream(s); // 将输入字符串转为流
    while (getline(tokenStream, token, delimiter)) { // 按分隔符分割
        if (!token.empty()) {     // 跳过空字符串（避免连续分隔符）
            tokens.push_back(token);
        }
    }
    return tokens;
}