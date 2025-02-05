// 前缀树模型
#include<iostream>
#include<vector>
using namespace std;


struct TrieNode
{
    int pass;
    int end;
    TrieNode* nexts[26];
    TrieNode() 
    {
        pass = 0;
        end = 0;
        // nexts[0]  == nullptr 没有走向'a'的路
        // nexts[0]  != nullptr 有走向'a'的路
        // ...
        // nexts[25] != nullptr 有走向'z'的路
        for (int i = 0; i < 26; i++) 
        {
            nexts[i] = nullptr;
        }
    }
};


struct Trie
{
    TrieNode* root;
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        if(word.empty()) return;
        TrieNode* node = root;
        for (char c : word) // 从左往右遍历字符
        {
            int index = c - 'a';  // 由字符，对应成走向哪条路
            if (node->nexts[index] == nullptr) 
            {
                node->nexts[index] = new TrieNode();
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }
};


int main()
{

    return 0;
}







