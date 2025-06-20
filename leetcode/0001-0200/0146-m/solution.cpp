// https://leetcode.com/problems/lru-cache
// 2025/06/16

class LRUCache {
    const int capacity;
    list<pair<int, int>> pairs;
    unordered_map<int, list<pair<int, int>>::iterator> map;

public:
    LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        const auto it = map.find(key);
        if (it == map.end()) return -1;

        pairs.splice(pairs.begin(), pairs, it->second);

        return it->second->second;
    }
    
    void put(int key, int value) {
        const auto it = map.find(key);
        if (it == map.end()) {
            pairs.emplace_front(key, value);
            map[key] = pairs.begin();
        } else {
            pairs.splice(pairs.begin(), pairs, it->second);
            it->second->second = value;
        }

        if (pairs.size() > capacity) {
            map.erase(pairs.back().first);
            pairs.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */