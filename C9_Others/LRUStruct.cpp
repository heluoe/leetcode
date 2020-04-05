#include <iostream>
#include <unordered_map>
#include <list>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        max_size = capacity;
    }

    int get(int key)
    {
        if (lru_map_node.find(key) == lru_map_node.end() || lru_node_map.empty())
            return -1;
        auto node = lru_map_node[key];
        auto pre_node = node->left;
        auto next_node = node->right;
        if (node == tail)
            return tail->val;
        if (node == head && head == tail)
            return head->val;
        else if (node == head)
        {
            head = next_node;
            next_node->left = nullptr;
            node->right = nullptr;
            node->left = tail;
            tail->right = node;
            tail = node;
        }
        else
        {
            pre_node->right = next_node;
            next_node->left = pre_node;
            node->left = tail;
            node->right = nullptr;
            tail->right = node;
            tail = node;
        }
        return tail->val;
    }

    void put(int key, int value)
    {
        if (max_size == 0)
            return;
        if (!head)
        {
            head = new DequeNode(value);
            tail = head;
            lru_map_node[key] = head;
            lru_node_map[head] = key;
            return;
        }
        if (get(key) != -1)
        {
            tail->val = value;
        }
        else if (max_size == lru_map_node.size())
        {
            auto pop_key = lru_node_map[head];
            lru_map_node.erase(pop_key);
            lru_node_map[head] = key;
            lru_map_node[key] = head;
            head->val = value;
            get(key);
        }
        else
        {
            lru_map_node[key] = new DequeNode(value);
            lru_node_map[lru_map_node[key]] = key;
            tail->right = lru_map_node[key];
            lru_map_node[key]->left = tail;
            tail = lru_map_node[key];
        }
    }

private:
    struct DequeNode
    {
        int val;
        DequeNode *left;
        DequeNode *right;
        DequeNode(int x) : val(x), left(NULL), right(NULL) {}
        DequeNode(int x, DequeNode *l, DequeNode *r) : val(x), left(l), right(r) {}
    };

private:
    std::unordered_map<int, DequeNode *> lru_map_node;
    std::unordered_map<DequeNode *, int> lru_node_map;
    DequeNode *head = nullptr, *tail = nullptr;
    int max_size = 0;
};

int main(int argc, char **argv)
{
    LRUCache myCache(3);
    myCache.put(1, 1);
    myCache.put(2, 2);
    myCache.put(3, 3);
    myCache.put(4, 4);
    std::cout << "get 4 " << myCache.get(4) << std::endl;
    std::cout << "get 3 " << myCache.get(3) << std::endl;
    std::cout << "get 2 " << myCache.get(2) << std::endl;
    std::cout << "get 1 " << myCache.get(1) << std::endl;
    myCache.put(5, 5);
    std::cout << "get 1 " << myCache.get(1) << std::endl;
    std::cout << "get 2 " << myCache.get(2) << std::endl;
    std::cout << "get 3 " << myCache.get(3) << std::endl;
    std::cout << "get 4 " << myCache.get(4) << std::endl;
    std::cout << "get 5 " << myCache.get(5) << std::endl;
    return 0;
}