// https://judge.beecrowd.com/en/problems/view/2897
// 2024/08/17

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

int main(void) {
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);

    u32 n, p;
    while (true) {
        cin >> n;

        if (n == 0) break;

        unordered_map<u32, u32> map;
        vector<u32> hist(n);
        for (u32 i = 0; i < n; ++i) {
            cin >> p;

            hist[i] = p;
            
            if (!map.count(p)) {
                map[p] = i;
            }
        }

        u32 total = 0;
        for (u32 i = 0; i < n; ++i) {
            if (map[hist[i]] == i) {
                total += hist[i] + i;
            } else {
                total += i - map[hist[i]];
                map[hist[i]] = i;
            }
        }

        cout << total << '\n';
    }

    return 0;
}