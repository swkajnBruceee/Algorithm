/* �����������л��ͷ����л�
   (�����ڴ����һ������α���ַ�����ʽ������δ��ַ�����ʽ����ڴ��������
   �������ж�һ�ö������ǲ�����һ�ö�����������)
*/
#include<iostream>
#include <vector>    // ��������
#include <queue>     // ��������
#include <string>    // �ַ�������
#include <sstream>   // �ַ���������
using namespace std; // ʹ�ñ�׼�����ռ�

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






// ���л�(����)
string serial_By_Pre(Node* head)
{
    if(head == nullptr) return "#_";
    string res = to_string(head->value) + "_";
    res += serial_By_Pre(head->left);
    res += serial_By_Pre(head->right);
    return res;
}


// �����л�(����)
Node* recon_By_PreString(string& preStr) 
{
    vector<string> values = split(preStr, '_'); // �ָ��ַ���
    queue<string> q;                            // ��������
    for (const string& val : values) {          // ���ָ����������
        q.push(val);
    }
    return reconPreOrder(q); // ���õݹ麯��������
}


Node* reconPreOrder(queue<string>& q) 
{
    string value = q.front(); // ��ȡ����Ԫ��
    q.pop();                  // ��������Ԫ�أ�ģ��Java��poll()��
    if (value == "#") {       // ��ֹ�����������սڵ���
        return nullptr;
    }
    Node* head = new Node(stoi(value)); // �����½ڵ㣨�ַ���ת������
    head->left = reconPreOrder(q);      // �ݹ鹹��������
    head->right = reconPreOrder(q);     // �ݹ鹹��������
    return head;
}

vector<string> split(string& s, char delimiter) 
{
    vector<string> tokens;        // �洢�ָ������ַ���
    string token;                 // ��ʱ�洢ÿ�����ַ���
    istringstream tokenStream(s); // �������ַ���תΪ��
    while (getline(tokenStream, token, delimiter)) { // ���ָ����ָ�
        if (!token.empty()) {     // �������ַ��������������ָ�����
            tokens.push_back(token);
        }
    }
    return tokens;
}