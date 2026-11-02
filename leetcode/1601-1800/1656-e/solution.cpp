// https://leetcode.com/problems/design-an-ordered-stream
// 2026/02/13

class OrderedStream {
    vector<string> v;
    int next_id;

public:
    OrderedStream(int n) : v(n), next_id() {}
    
    vector<string> insert(int idKey, string value) {
        v[--idKey] = move(value);

        if (idKey != next_id) return {};

        const int last_id = next_id;
        while (next_id < v.size() && !v[next_id].empty()) {
            ++next_id;
        }

        return {move_iterator(next(v.begin(), last_id)), move_iterator(next(v.begin(), next_id))};
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */