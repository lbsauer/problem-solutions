// https://leetcode.com/problems/insert-delete-getrandom-o1
// 2024/08/21

class RandomizedSet {
    unordered_map<int, int> map;
    vector<int> vec;

    random_device rd;
    mt19937 gen;

public:
    RandomizedSet() {
        gen = mt19937(rd());
    }
    
    bool insert(int val) {
        if (map.count(val)) return false;

        vec.push_back(val);
        map[val] = vec.size() - 1;

        return true;
    }
    
    bool remove(int val) {
        const auto it = map.find(val);

        if (it == map.end()) return false;

        map[vec.back()] = it->second;
        swap(vec[it->second], vec.back());
        map.erase(it);
        vec.pop_back();

        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> distrib(0, vec.size() - 1);

        return vec[distrib(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */