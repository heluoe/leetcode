/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(Node *root)
    {
        if (root == NULL)
            return "";
        queue<Node *> buf;
        buf.push(root);
        string res = "";
        while (!buf.empty())
        {
            int n = buf.size();
            for (int i = 0; i < n; ++i)
            {
                Node *p = buf.front();
                buf.pop();
                res += (to_string(p->val) + "-");
                res += (to_string(p->children.size()) + " ");
                for (int j = 0; j < p->children.size(); ++j)
                    buf.push(p->children[j]);
            }
        }
        //cout << res << endl;
        return res;
    }

    template <char delimiter>
    class WordDelimitedBy : public std::string
    {
    };
    // Decodes your encoded data to tree.
    Node *deserialize(string data)
    {
        if (data.empty())
            return NULL;

        istringstream iss(data);
        vector<string> results((istream_iterator<string>(iss)),
                               istream_iterator<string>());

        Node *root, *node;
        vector<string> ps(2);
        queue<int> buff;
        int spl = results[0].find('-');
        ps[0] = results[0].substr(0, spl);
        ps[1] = results[0].substr(spl + 1);

        int r = 1, l = stoi(ps[1]);
        root = new Node(stoi(ps[0]));
        root->children.resize(l);
        queue<Node *> buf;
        buf.push(root);
        while (!buf.empty())
        {
            int n = buf.size();

            for (int k = 0; k < n; ++k)
            {
                node = buf.front();
                buf.pop();

                int l2 = node->children.size();
                for (int i = r; i < r + l2; ++i)
                {
                    int spl = results[i].find('-');
                    ps[0] = results[i].substr(0, spl);
                    ps[1] = results[i].substr(spl + 1);
                    node->children[i - r] = new Node(stoi(ps[0]));
                    node->children[i - r]->children.resize(stoi(ps[1]));
                    buf.push(node->children[i - r]);
                }
                r += l2;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));