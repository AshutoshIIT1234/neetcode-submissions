struct TrieNode {
    TrieNode* children[26];
    bool isEnd;

    TrieNode() : isEnd(false) {
        fill(begin(children), end(children), nullptr);
    }
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
            int idx = c - 'a';
            if (!curr->children[idx])
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = traverse(word);
        return node && node->isEnd;   // must exist AND be a complete word
    }

    bool startsWith(string prefix) {
        return traverse(prefix);      // just needs to exist
    }

private:
    // shared helper: walk the trie, return final node or nullptr
    TrieNode* traverse(const string& s) {
        TrieNode* curr = root;
        for (char c : s) {
            int idx = c - 'a';
            if (!curr->children[idx]) return nullptr;
            curr = curr->children[idx];
        }
        return curr;
    }
};
