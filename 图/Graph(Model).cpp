// ͼ�Ļ���ģ��
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

struct Node
{
    int value;
    int in;               // һ��������(�ж��ٸ��㷢ɢ���ı���ֱ��ָ�򱾵��)
    int out;              // һ����ĳ���(�����ж������߷�ɢ��ȥָ��������)
    vector<Node*> nexts;  // ���㷢ɢ��ȥ�ı�ָ��ĵ�
    vector<Edge*> edges;  // ���ڱ���ı�����Щ
    Node(int value) {
        this->value = value;
        in = 0;
        out = 0;
        nexts = vector<Node*>();
        edges = vector<Edge*>();
    }
};

struct Edge
{
    int weight;  // Ȩֵ(����)
    Node* from;
    Node* to;
    Edge(int weight, Node* from, Node* to)
    {
        this->weight = weight;
        this->from = from;
        this->to = to;
    }
};

struct Graph
{
    unordered_map<int,Node*> nodes;  // �㼯
    unordered_set<Edge*> edges;      // �߼�
    Graph()
    {
        nodes = unordered_map<int,Node*>();
        edges = unordered_set<Edge*>();
    }
};



