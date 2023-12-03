#include "LeetCodeBase.h"

struct TrieNode{
    bool isWord;
    char c;
    vector<TrieNode*> children;
    TrieNode(char _c, bool _isWord) : c(_c), isWord(_isWord), children(26, nullptr){}
    TrieNode(char _c) : c(_c), isWord(false), children(26, nullptr){}
};

class Trie {
    TrieNode *dummyNode = nullptr;
public:
    Trie() {
        dummyNode = new TrieNode('a', false);
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode *node = dummyNode;
        for(int i = 0; i < n; ++i){
            if(node->children[word[i] - 'a'] == nullptr){
                node->children[word[i] - 'a'] = new TrieNode(word[i]);
            }
            node = node->children[word[i] - 'a'];
            if(i == n - 1){
                node->isWord = true;
            }
        }
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode *node = dummyNode;
        bool isWord = false;
        for(int i = 0; i < n; ++i){
            node = node->children[word[i] - 'a'];
            if(node == nullptr){
                return false;
            }
            if(i == n - 1){
                isWord = node->isWord;
            }
        }
        return isWord;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode *node = dummyNode;
        for(int i = 0; i < n; ++i){
            node = node->children[prefix[i] - 'a'];
            if(node == nullptr){
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){
    Trie trie;
    trie.insert("apple");
    bool isTrue = trie.search("apple");
    isTrue = trie.search("app");
    isTrue = trie.startsWith("app");
    trie.insert("app");
    isTrue = trie.search("app");

    return 0;
}