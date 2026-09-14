#include <string>
using namespace std;

class Trie {
    struct Node {
        Node* next[26]{};
        bool end = false;
    };
    Node* root = new Node();
public:
    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a']) cur->next[c - 'a'] = new Node();
            cur = cur->next[c - 'a'];
        }
        cur->end = true;
    }
    bool search(string word) {
        Node* cur = root;
        for (char c : word) {
            if (!cur->next[c - 'a']) return false;
            cur = cur->next[c - 'a'];
        }
        return cur->end;
    }
    bool startsWith(string prefix) {
        Node* cur = root;
        for (char c : prefix) {
            if (!cur->next[c - 'a']) return false;
            cur = cur->next[c - 'a'];
        }
        return true;
    }
};
