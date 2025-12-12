// https://leetcode.com/problems/implement-trie-prefix-tree
// 2025/12/10

class Trie {
    struct trie_node {
        bool end = false;
        trie_node* nodes[26]{};
    };

    trie_node root;

public:
    Trie() {}
    
    void insert(string word) {
        trie_node* curr = &root;
        for (const char c : word) {
            if (curr->nodes[c - 'a'] == nullptr) {
                curr->nodes[c - 'a'] = new trie_node;
            }

            curr = curr->nodes[c - 'a'];
        }

        curr->end = true;
    }
    
    bool search(string word) {
        trie_node* curr = &root;
        for (const char c : word) {
            if (curr->nodes[c - 'a'] == nullptr) return false;

            curr = curr->nodes[c - 'a'];
        }

        return curr->end;
    }
    
    bool startsWith(string prefix) {
        trie_node* curr = &root;
        for (const char c : prefix) {
            if (curr->nodes[c - 'a'] == nullptr) return false;

            curr = curr->nodes[c - 'a'];
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