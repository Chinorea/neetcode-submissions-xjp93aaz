class TrieNode{
public: 
    unordered_map<char, TrieNode*> child;
    bool endOfWord = false;
};

class PrefixTree {
    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if(curr->child.find(c) == curr->child.end()){
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            if (curr->child.find(c) == curr->child.end()) return false;
            curr = curr->child[c];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c: prefix) {
            if (curr->child.find(c) == curr->child.end()) return false;
            curr = curr->child[c];
        }
        return true;
    }
};
