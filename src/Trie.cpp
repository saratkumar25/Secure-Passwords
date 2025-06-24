#include "../include/Trie.h"

TrieNode::TrieNode() : isEndOfWord(false) {}

Trie::Trie() { root = new TrieNode(); }

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children[ch]) node->children[ch] = new TrieNode();
        node = node->children[ch];
    }
    node->isEndOfWord = true;
}

bool Trie::search(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        if (!node->children[ch]) return false;
        node = node->children[ch];
    }
    return node->isEndOfWord;
}
