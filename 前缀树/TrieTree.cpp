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

    // 加入一个字符串
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

    
    // word这个单词之前加入过几次
    int search(string word)
    {
        if(word.empty()) return 0;
        TrieNode* node = root;
        for(char c : word)
        {
            int index = c - 'a';
            if (node->nexts[index] == nullptr) 
            {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }

    // 所有加入的字符串中，有几个是以pre这个字符串作为前缀的
    int prefixNumber(string pre)
    {
        if(pre.empty()) return 0;
        TrieNode* node = root;
        for(char c : pre)
        {
            int index = c - 'a';
            if (node->nexts[index] == nullptr) 
            {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->pass;
    }

    // 删除字符串
    void myDelete(string word)
    {
        if(search(word) != 0)  // 确定树中确实加入过word,才删除
        {
            TrieNode* node = root;
            node->pass--;
            for(char c : word)
            {
                int index = c - 'a';
                node = node->nexts[index];
            }
            node->end--;
        }
    }

};


int main()
{

    return 0;
}






