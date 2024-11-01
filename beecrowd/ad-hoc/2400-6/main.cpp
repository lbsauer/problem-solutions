// https://judge.beecrowd.com/en/problems/view/2400
// 2024/08/28

#include <bits/stdc++.h>

typedef uint32_t u32;
typedef uint64_t u64;

using namespace std;

inline size_t lsb(size_t x) { return x - (x & (x - 1)); }

template <class T>
class Fenwick {
    size_t size;
    T* values;

public:
    Fenwick(size_t size) : size(size), values((T*) malloc((size + 1) * sizeof(T))) {
        for (size_t i = 0; i <= size; ++i) values[i] = T{};
    }

    ~Fenwick() { free(values); }

    void update(size_t idx, T val) {
        while (idx <= size) {
            values[idx] += val;
            idx += lsb(idx);
        }
    }

    T sum(size_t idx) {
        T sum{};
        while (idx > 0) {
            sum += values[idx];
            idx -= lsb(idx);
        }
        return sum;
    }
};

int main(void) {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    u32 n, g;
    cin >> n;

    Fenwick<u32> fw(n);
    vector<u32> girls(n);

    for (u32 i = 0; i < n; ++i) {
        cin >> g;
        
        girls[i] = g;
        fw.update(g, 1);
    }

    u64 total = 0;
    for (int i = 0; i < n; ++i) {
        fw.update(girls[i], -1);
        total += fw.sum(girls[i]);
    }

    cout << total << '\n';

    return 0;
}