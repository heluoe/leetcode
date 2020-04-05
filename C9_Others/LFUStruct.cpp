#include <iostream>
#include <unordered_map>
#include <list>
#include <random>
#include <algorithm>
#include <cmath>
using namespace std;
class LFUCache
{
public:
    LFUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (m.count(key) == 0)
            return -1;
        freq[m[key].second].erase(l[key]);
        m[key].second++;
        freq[m[key].second].push_back(key);
        l[key] = --freq[m[key].second].end();
        if (freq[minFreq].size() == 0)
            minFreq++;
        return m[key].first;
    }

    void put(int key, int value)
    {
        if (cap <= 0)
            return;
        if (get(key) != -1)
        {
            m[key].first = value;
            return;
        }
        if (m.size() >= cap)
        {
            m.erase(freq[minFreq].front());
            l.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        m[key] = make_pair(value, 1);
        freq[1].push_back(key);
        l[key] = --freq[1].end();
        minFreq = 1;
    }

private:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> m;
    unordered_map<int, list<int>> freq;
    unordered_map<int, list<int>::iterator> l;
};

int main(int argc, char **argv)
{
    LFUCache myCache(3);
    myCache.put(2, 2);
    myCache.put(1, 1);
    std::cout << myCache.get(2) << std::endl;
    std::cout << myCache.get(1) << std::endl;
    std::cout << myCache.get(2) << std::endl;
    myCache.put(3, 3);
    myCache.put(4, 4);
    std::cout << myCache.get(3) << std::endl;
    std::cout << myCache.get(2) << std::endl;
    std::cout << myCache.get(1) << std::endl;
    std::cout << myCache.get(4) << std::endl;
    return 0;
}