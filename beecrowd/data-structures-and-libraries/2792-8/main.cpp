// https://judge.beecrowd.com/en/problems/view/2792
// 2024/08/27

#include <bits/stdc++.h>

typedef int8_t    i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;
typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float    f32;
typedef double   f64;

#define  I8MIN   INT8_MIN
#define I16MIN  INT16_MIN
#define I32MIN  INT32_MIN
#define I64MIN  INT64_MIN
#define  I8MAX   INT8_MAX
#define I16MAX  INT16_MAX
#define I32MAX  INT32_MAX
#define I64MAX  INT64_MAX
#define  U8MAX  UINT8_MAX
#define U16MAX UINT16_MAX
#define U32MAX UINT32_MAX
#define U64MAX UINT64_MAX

using namespace std;

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const pair<T, U>& p) {
    return os << '[' << p.first << ' ' << p.second << ']';
}

template <class ForwardIt>
void print(ForwardIt begin, ForwardIt end) {
    if (begin == end) return;

    cout << *begin;
    while (++begin != end) {
        cout << ' ' << *begin;
    }
    cout << '\n';
}

inline size_t lsb(size_t x) { return x - (x & (x - 1)); }

template <class T>
class Fenwick {
    size_t size;
    T* values;

public:
    Fenwick(size_t size) : size(size), values((T*) calloc(sizeof(T), size + 1)) {}
    ~Fenwick() { free(values); }

    void add(size_t idx, T val) {
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

    i32 n, x;
    cin >> n;

    Fenwick<u64> fw(n);

    while (n-- > 0) {
        cin >> x;

        cout << (x - fw.sum(x)) << (n == 0 ? '\n' : ' ');

        fw.add(x, 1);
    }

    return 0;
}