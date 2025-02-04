// ͼ�Ļ���ģ��
#include<unordered_map>
#include<vector>
using namespace std;

struct Node;

struct Edge
{
    int weight;  // Ȩֵ(����)
    Node* fromNode;
    Node* toNode;
    Edge(int weight, Node* fromNode, Node* toNode)
    {
        this->weight = weight;
        this->fromNode = fromNode;
        this->toNode = toNode;
    }
};

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



struct Graph
{
    unordered_map<int,Node> nodes;  // �㼯
    vector<Edge*> edges;      // �߼�

    // �����������
    ~Graph() {
        // �ͷ�����Edge����
        for (Edge* edge : edges) {
            delete edge;
        }
        edges.clear();  // ���ָ�루�Ǳ��룩
    }
};



