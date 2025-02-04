// 图的基础模型
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;

struct Node
{
    int value;
    int in;               // 一个点的入度(有多少个点发散出的边是直接指向本点的)
    int out;              // 一个点的出度(本点有多少条边发散出去指向其他点)
    vector<Node*> nexts;  // 本点发散出去的边指向的点
    vector<Edge*> edges;  // 属于本点的边有哪些
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
    int weight;  // 权值(距离)
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
    unordered_map<int,Node*> nodes;  // 点集
    unordered_set<Edge*> edges;      // 边集
    Graph()
    {
        nodes = unordered_map<int,Node*>();
        edges = unordered_set<Edge*>();
    }
};



