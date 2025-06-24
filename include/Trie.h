#ifndef TRIE_H
#define TRIE_H
#include <unordered_map>
#include <string>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode();
};

class Trie {
public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word);
private:
    TrieNode* root;
};
#endif
