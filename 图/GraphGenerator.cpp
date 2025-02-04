// 接口函数
#include "Graph.cpp"
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// matrix所有的边
// N*3的矩阵

Graph createGraph(int** matrix, int rowCount) {
    Graph graph;
    for (int i = 0; i < rowCount; i++) {
        int from = matrix[i][0];
        int to = matrix[i][1];
        int weight = matrix[i][2];
        if (graph.nodes.find(from) == graph.nodes.end()) {
            graph.nodes[from] = Node(from);
        }
        if (graph.nodes.find(to) == graph.nodes.end()) {
            graph.nodes[to] = Node(to);
        }
        Node* fromNode = &graph.nodes[from];
        Node* toNode = &graph.nodes[to];
        Edge* newEdge = new Edge(weight, fromNode, toNode);
        fromNode->nexts.push_back(toNode);
        fromNode->out++;
        toNode->in++;
        fromNode->edges.push_back(newEdge);
        graph.edges.push_back(newEdge);
    }
    return graph;
}
