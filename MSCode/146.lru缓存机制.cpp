/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap_ = capacity;
        idx_ = 0;
        tail_ = head_ = NULL;
    }

    int get(int key)
    {
        if (cache_map.empty() || cache_map.find(key) == cache_map.end())
        {
            return -1;
        }
        DequeNode *cache_node = cache_map[key];
        move_node_to_tail(cache_node);
        return cache_node->val;
    }

    void put(int key, int value)
    {
        if (cache_map.empty())
        {
            head_ = new DequeNode(key, value);
            tail_ = head_;
            cache_map[key] = head_;
            idx_++;
        }
        else if (cache_map.find(key) != cache_map.end())
        {
            DequeNode *cache_node = cache_map[key];
            cache_node->val = value;
            move_node_to_tail(cache_node);
        }
        else if (idx_ < cap_)
        {
            DequeNode *node = new DequeNode(key, value);
            insert_node_to_tail(node);
            cache_map[key] = node;
            idx_++;
        }
        else
        {
            DequeNode *node = head_;
            cache_map.erase(node->key);
            if (head_ == tail_)
                tail_ = NULL;
            head_ = head_->next;
            if (head_ != NULL)
                head_->front = NULL;

            node->front = node->next = NULL;
            node->key = key;
            node->val = value;
            insert_node_to_tail(node);
            cache_map[key] = node;
        }
    }

private:
    struct DequeNode
    {
        int val;
        int key;
        DequeNode *next, *front;
        DequeNode(int k, int x) : key(k), val(x), next(NULL), front(NULL) {}
    };

    void insert_node_to_tail(DequeNode *cache_node)
    {
        if (tail_ != NULL)
        {
            tail_->next = cache_node;
            cache_node->front = tail_;
            cache_node->next = NULL;
            tail_ = cache_node;
        }
        else
        {
            if (head_ == NULL)
                head_ = cache_node;
            tail_ = cache_node;
        }
    }

    void move_node_to_tail(DequeNode *cache_node)
    {
        if (head_ == tail_ || tail_ == cache_node)
        {
        }
        else if (head_ == cache_node)
        {
            head_ = head_->next;
            head_->front = NULL;
            tail_->next = cache_node;
            cache_node->front = tail_;
            cache_node->next = NULL;
            tail_ = cache_node;
        }
        else
        {
            DequeNode *tmp = cache_node->front;
            tmp->next = cache_node->next;
            if (cache_node->next)
                cache_node->next->front = tmp;

            tail_->next = cache_node;
            cache_node->front = tail_;
            cache_node->next = NULL;
            tail_ = cache_node;
        }
    }

protected:
    int cap_, idx_;
    unordered_map<int, DequeNode *> cache_map;
    DequeNode *head_, *tail_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
// ["LRUCache","put","get","put","get","get"]\n [[1],[2,1],[2],[3,2],[2],[3]] \n
