// https://judge.beecrowd.com/en/problems/view/2902
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

    u16 n, j, c;
    while (true) {
        cin >> n >> j;

        if (n == 0) break;

        deque<u16> deck;
        while (n-- > 0) {
            cin >> c;
            deck.push_back(c);
        }

        vector<pair<u16, u16>> players(j, {0, 0});
        vector<bool> discard(14);
        u16 i = 0;
        u16 card;

        while (!deck.empty()) {
            card = deck.front();
            deck.pop_front();

            if (discard[card]) {
                discard[card] = false;
                players[i].first += 2;
                players[i].second = card;
            } else if (players[i].second == card) {
                players[i].first += 1;
            } else if (auto it = find_if(players.begin(), players.end(), [&](auto p) { return p.second == card; }); it != players.end()) {
                players[i].first += it->first + 1;
                players[i].second = card;
                it->first = 0;
                it->second = 0;
            } else {
                discard[card] = true;
                i = (i + 1) % j;
            }
        }

        u16 max = max_element(players.begin(), players.end(), [](const auto lhs, const auto rhs) {
            return lhs.first < rhs.first;
        })->first;

        cout << max;
        for (i = 0; i < j; ++i) {
            if (players[i].first == max) {
                cout << ' ' << (i + 1);
            }
        }
        cout << '\n';
    }

    return 0;
}