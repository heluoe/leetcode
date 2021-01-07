/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
#define ALPHABET_SIZE 26
class Solution
{
public:
    struct trie_node
    {
        string word = "";
        shared_ptr<trie_node> child[ALPHABET_SIZE];
        shared_ptr<trie_node> front;
    };
    shared_ptr<trie_node> create_trie_node(char k = ' ')
    {
        auto node = make_shared<trie_node>();
        for (int i = 0; i < ALPHABET_SIZE; ++i)
            node->child[i] = nullptr;
        node->word = "";
        return node;
    }

    void insert_trie_tree(const string &word)
    {
        auto node = root_;
        for (const auto c : word)
        {
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = create_trie_node(c);
            node->child[c - 'a']->front = node;
            node = node->child[c - 'a'];
        }
        node->word = word;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {

        root_ = create_trie_node();
        row_ = board.size();
        if (row_ < 1)
            return results_;
        col_ = board[0].size();
        for (const auto &w : words)
        {
            insert_trie_tree(w);
        }
        shared_ptr<trie_node> node = nullptr;
        for (int i = 0; i < row_; ++i)
        {
            for (int j = 0; j < col_; ++j)
            {
                bfs(board, root_, i, j);
            }
        }
        return results_;
    }
    vector<vector<int>> dirs_ = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(vector<vector<char>> &board, shared_ptr<trie_node> node, int i, int j)
    {
        if (i < 0 || i >= row_ || j < 0 || j >= col_)
            return;
        char t = board[i][j];
        if (t == '*' || node->child[t - 'a'] == nullptr)
            return;
        node = node->child[t - 'a'];
        if (node->word != "")
        {
            results_.push_back(node->word);
            node->word = "";
            // ! important cannot return! banan word and banana also need to find!
        }
        board[i][j] = '*';
        for (const auto &dir : dirs_)
        {

            bfs(board, node, i + dir[0], j + dir[1]);
        }
        board[i][j] = t;

        return;
    }
    int row_, col_;
    shared_ptr<trie_node> root_;
    vector<string> results_;
};
// @lc code=end
// [["a","a"]]\n["aaa"]
// [["a","b"],["c","d"]]\n["ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb"]
// [["a","b","c"],["a","e","d"],["a","f","g"]]\n["abcdefg","gfedcbaaa","eaabcdgfa","befa","dgc","ade"]
// [["a","a","a","a"],["a","a","a","a"],["a","a","a","a"]]\n["aaaaaaaaaaaa","aaaaaaaaaaaaa","aaaaaaaaaaab"]

// [
// ["s","e","e","n","e","w"],
// ["t","m","r","i","v","a"],
// ["o","b","s","i","b","d"],
// ["w","m","y","s","e","n"],
// ["l","t","s","n","s","a"],
// ["i","e","z","l","g","n"]]
// ["stow","stob","seer","seen","embow","neem","wadna","wave","wene","renew","reem","reest","rine","riva","inerm","vine","viner","avener","avine","bowl","sise","besa","bena","bend","daven","wots","myst","send","teil","sang","sand","sane","anda","anes","anesis","nane"]

// ["anda","anes","anesis","avener","avine","bena","bend","benda","besa","besan","bowl","daven","embow","inerm","irene","myst","nane","nanes","neem","reem","reest","renew","rine","riva","rive","riven","sand","sane","sang","seen","seer","send","sise","stob","stow","teil","vine","viner","vire","wadna","wave","wene","wots"]