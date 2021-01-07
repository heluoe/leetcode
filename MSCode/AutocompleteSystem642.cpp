class AutocompleteSystem
{
public:
    struct TrieNode
    {
        int times = -1;
        string sentence = "";
        shared_ptr<TrieNode> child[27];
        set<char> exists;
    };

    shared_ptr<TrieNode> create_trie_node()
    {
        auto node = make_shared<TrieNode>();
        node->times = 0;
        node->exists.clear();
        for (int i = 0; i < 27; ++i)
            node->child[i] = nullptr;
        return node;
    }

    void insert_char(char c, shared_ptr<TrieNode> &node)
    {
        node->exists.insert(c);
        if (c == ' ')
        {
            if (node->child[26] == NULL)
                node->child[26] = create_trie_node();
            node = node->child[26];
        }
        else
        {
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = create_trie_node();
            node = node->child[c - 'a'];
        }
    }

    void insert(string word, int times)
    {
        auto node = root_;
        for (int i = 0; i < word.length(); ++i)
        {

            insert_char(word[i], node);
        }
        node->times = times;
        node->sentence = word;
    }

    AutocompleteSystem(vector<string> &sentences, vector<int> &times)
    {
        root_ = create_trie_node();
        node_ = root_;

        for (int i = 0; i < sentences.size(); ++i)
        {
            insert(sentences[i], times[i]);
        }
    }

    void dfs(shared_ptr<TrieNode> &p)
    {
        if (p->times > 0)
        {
            dfs_buf.push_back({p->sentence, p->times});
        }
        if (p->exists.empty())
        {
            return;
        }
        for (auto e : p->exists)
        {
            if (e == ' ')
                dfs(p->child[26]);
            else
                dfs(p->child[e - 'a']);
        }
    }

    void search(char c)
    {
        vector<string> cur;
        insert_char(c, node_);
        if (dfs_buf.empty())
        {
            dfs(node_);
            sort(dfs_buf.begin(), dfs_buf.end(), [](pair<string, int> &a, pair<string, int> &b) {
                if (a.second == b.second)
                {
                    return a.first < b.first;
                    // for(int i=0, j=0; i<a.first.length() && j<b.first.length(); ++i,++j)
                    //     if(a.first[i] != b.first[j])
                    //         return a.first[i] > b.first[j];
                    // return a.first.length() > b.first.length();
                }
                return a.second > b.second;
            });
            for (int i = 0; i < dfs_buf.size(); ++i)
            {

                cur.push_back(dfs_buf[i].first);
                if (cur.size() > 2)
                    break;
            }
        }
        else
        {
            for (int i = 0; i < dfs_buf.size(); ++i)
            {
                if (dfs_buf[i].first[idx_] == c)
                    cur.push_back(dfs_buf[i].first);

                if (cur.size() > 2)
                    break;
            }
        }
        swap(cur, res_);
    }

    vector<string> input(char c)
    {

        if (c == '#')
        {
            node_->times++;
            node_->sentence = buf;
            node_ = root_;
            idx_ = 0;
            res_.clear();
            dfs_buf.clear();
            buf = "";
            return res_;
        }
        else if (node_->exists.empty() || node_->exists.find(c) == node_->exists.end())
        {
            insert_char(c, node_);
            res_.clear();
            dfs_buf.clear();
        }
        else
        {
            search(c);
        }
        buf += string(1, c);
        idx_++;
        return res_;
    }
    string buf;
    vector<pair<string, int>> dfs_buf;
    shared_ptr<TrieNode> root_, node_;
    int idx_ = 0;
    vector<string> res_;
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */