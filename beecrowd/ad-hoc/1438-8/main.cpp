// https://judge.beecrowd.com/en/problems/view/1438
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

    i16 n, p, q, b;
    while (true) {
        cin >> n >> p;

        if (n == 0) break;

        pair<i16, i16> one;
        vector<i16> stacks(p);
        for (i16 i = 0; i < p; ++i) {
            cin >> q;

            stacks[i] = q;

            for (i16 j = 0; j < q; ++j) {
                cin >> b;

                if (b == 1) {
                    one = {i, j};
                }
            }
        }

        for (i16 i = 0; i < p; ++i) {
            stacks[i] -= one.second;
        }

        i16 left = 0;
        for (i16 i = one.first; i >= 0 && stacks[i] > 0; --i) {
            left += stacks[i];
        }

        i16 right = 0;
        for (i16 i = one.first; i < p && stacks[i] > 0; ++i) {
            right += stacks[i];
        }

        cout << (min(left, right) - 1) << '\n';
    }

    return 0;
}