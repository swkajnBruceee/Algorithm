// ǰ׺��ģ��
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
        // nexts[0]  == nullptr û������'a'��·
        // nexts[0]  != nullptr ������'a'��·
        // ...
        // nexts[25] != nullptr ������'z'��·
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
        for (char c : word) // �������ұ����ַ�
        {
            int index = c - 'a';  // ���ַ�����Ӧ����������·
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







