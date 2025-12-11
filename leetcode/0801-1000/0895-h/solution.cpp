// https://leetcode.com/problems/maximum-frequency-stack
// 2025/08/22

class FreqStack {
    int max_freq;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> values;

public:
    FreqStack() : max_freq() {}
    
    void push(int val) {
        const int f = ++freq[val];
        max_freq = max(max_freq, f);
        values[f].push_back(val);
    }
    
    int pop() {
        const auto it = values.find(max_freq);

        const int res = it->second.back();
        it->second.pop_back();

        if (const auto it2 = freq.find(res); --it2->second == 0) {
            freq.erase(it2);
        }

        if (it->second.empty()) {
            --max_freq;
            values.erase(it);
        }

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */