/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    template <char delimiter>
    class WordDelimitedBy : public string
    {
    };
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        vector<string> vec_res;
        if (root == NULL)
            return res;
        queue<TreeNode *> tree_queue;
        tree_queue.push(root);
        while (!tree_queue.empty())
        {
            int n = tree_queue.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = tree_queue.front();
                tree_queue.pop();
                if (node != NULL)
                {
                    vec_res.push_back(to_string(node->val));
                    tree_queue.push(node->left);
                    tree_queue.push(node->right);
                }
                else
                {
                    vec_res.push_back("null");
                }
            }
        }
        int len = vec_res.size() - 1;
        for (; len >= 0; --len)
        {
            if (vec_res[len] != "null")
                break;
        }
        for (int i = 0; i <= len; ++i)
        {
            if (i != len)
                res = res + vec_res[i] + " ";
            else
            {
                res = res + vec_res[i];
            }
        }
        // cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        istringstream iss(data);
        vector<string> vals((istream_iterator<string>(iss)),
                            istream_iterator<string>());

        int n = vals.size();
        vector<TreeNode *> nodes;

        for (int i = 0; i < n; ++i)
        {
            if (vals[i] != "null")
                nodes.push_back(new TreeNode(stoi(vals[i])));
            else
                nodes.push_back(NULL);
        }
        int null_base = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nodes[i] == NULL)
            {
                null_base++;
                continue;
            }
            int lc = (i - null_base) * 2 + 1;
            if (lc < n)
            {
                nodes[i]->left = nodes[lc];
            }
            int rc = (i - null_base) * 2 + 2;
            if (rc < n)
            {
                nodes[i]->right = nodes[rc];
            }
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

// [1,2,3,null,null,4,5,6,7]