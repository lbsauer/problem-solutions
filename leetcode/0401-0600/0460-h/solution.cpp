// https://leetcode.com/problems/lfu-cache
// 2025/06/17

class LFUCache {
    using kv_pair   = pair<int, int>;
    using list_iter = list<kv_pair>::iterator;
    using freq_iter = list<pair<int, list<kv_pair>>>::iterator;

    const int capacity;
    list<pair<int, list<kv_pair>>> freq;
    unordered_map<int, pair<list_iter, freq_iter>> map;

public:
    LFUCache(int capacity) : capacity(capacity) {}

    freq_iter update(list_iter l_it, freq_iter f_it) {
        freq_iter next_it = next(f_it);
        if (next_it == freq.end() || next_it->first != f_it->first + 1) {
            next_it = freq.emplace(next_it, f_it->first + 1, list<kv_pair>{});
        }

        next_it->second.splice(next_it->second.begin(), f_it->second, l_it);

        if (f_it->second.empty()) freq.erase(f_it);

        return next_it;
    }
    
    int get(int key) {
        const auto it = map.find(key);
        if (it == map.end()) return -1;

        it->second.second = update(it->second.first, it->second.second);

        return it->second.first->second;
    }
    
    void put(int key, int value) {
        if (const auto it = map.find(key); it != map.end()) {
            it->second.second = update(it->second.first, it->second.second);
            it->second.first->second = value;
            return;
        }

        if (map.size() == capacity) {
            map.erase(freq.front().second.back().first);
            freq.front().second.pop_back();

            if (freq.front().second.empty()) freq.pop_front();
        }

        if (freq.empty() || freq.front().first != 1) {
            freq.emplace_front(1, list<kv_pair>{});
        }

        freq.front().second.emplace_front(key, value);
        map.emplace(key, make_pair(freq.front().second.begin(), freq.begin()));
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */