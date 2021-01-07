/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!right_.empty())
        {
            left_.push(right_.top());
            right_.pop();
        }
        left_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while (!left_.empty())
        {
            right_.push(left_.top());
            left_.pop();
        }
        int res = right_.top();
        right_.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        while (!left_.empty())
        {
            right_.push(left_.top());
            left_.pop();
        }
        return right_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return (left_.empty() && right_.empty());
    }

private:
    stack<int> left_;
    stack<int> right_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
