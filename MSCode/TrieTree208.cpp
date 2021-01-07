/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
#define ALPHABET_SIZE 26
class Trie
{
public:
    struct trie_node
    {
        bool isword;
        shared_ptr<trie_node> child[ALPHABET_SIZE];
    };
    shared_ptr<trie_node> create_trie_node()
    {
        auto node = make_shared<trie_node>();
        node->isword = false;
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            node->child[i] = nullptr;
        return node;
    }

    /** Initialize your data structure here. */
    Trie()
    {
        root_ = create_trie_node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        auto node = root_;
        for (int i = 0; i < word.length(); ++i)
        {
            if (node->child[word[i] - 'a'] == nullptr)
            {
                node->child[word[i] - 'a'] = create_trie_node();
            }
            node = node->child[word[i] - 'a'];
        }
        node->isword = true;
        // word_map[word] = word;
        // for (int i = 0; i < word.length(); ++i)
        // {
        //     trie_set[word.substr(0, i + 1)] = word;
        // }
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        auto node = root_;
        for (auto c : word)
        {
            if (node->child[c - 'a'] != nullptr)
            {
                node = node->child[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return node->isword;
        //return word_map.find(word) != word_map.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto node = root_;
        for (auto c : prefix)
        {
            if (node->child[c - 'a'] != nullptr)
            {
                node = node->child[c - 'a'];
            }
            else
            {
                return false;
            }
        }
        return true;
        //return trie_set.find(prefix) != trie_set.end();
    }
    shared_ptr<trie_node> root_;

    // unordered_map<string, string> word_map;
    // unordered_map<string, string> trie_set;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
