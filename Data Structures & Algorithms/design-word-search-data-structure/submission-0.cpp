class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        TrieNode() : isEnd(false) {
            fill(begin(children), end(children), nullptr);
        }
    };

    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int idx) {
        if (idx == word.size()) return node->isEnd;

        char c = word[idx];

        if (c == '.') {
            // Try all possible children
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && dfs(node->children[i], word, idx + 1))
                    return true;
            }
            return false;
        } else {
            int i = c - 'a';
            if (!node->children[i]) return false;
            return dfs(node->children[i], word, idx + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i])
                curr->children[i] = new TrieNode();
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
