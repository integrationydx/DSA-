class TrieNode
{
public:
    TrieNode* child[26];
    bool end;

    TrieNode()
    {
        end = false;

        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }
};

class WordDictionary {
public:

    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {

        TrieNode* node = root;

        for(char c : word)
        {
            int idx = c - 'a';

            if(node->child[idx] == NULL)
            {
                node->child[idx] = new TrieNode();
            }

            node = node->child[idx];
        }

        node->end = true;
    }

    bool dfs(TrieNode* node, string &word, int pos)
    {
        if(pos == word.size())
        {
            return node->end;
        }

        if(word[pos] == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(node->child[i] != NULL)
                {
                    if(dfs(node->child[i], word, pos + 1))
                        return true;
                }
            }

            return false;
        }

        int idx = word[pos] - 'a';

        if(node->child[idx] == NULL)
            return false;

        return dfs(node->child[idx], word, pos + 1);
    }

    bool search(string word) {

        return dfs(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */