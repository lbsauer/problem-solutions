// https://judge.beecrowd.com/en/problems/view/1409
// 2024/08/23

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

    i32 m, n, g, k, a, b;

    while (true) {
        cin >> m >> n >> g >> k;

        if (m == 0) break;

        vector<pair<i32, i32>> spells(m); // f: cost s: dmg
        for (i32 i = 0; i < m; ++i) {
            cin >> a >> b;

            spells[i] = {a, b};
        }

        vector<vector<i32>> graph(n);
        for (i32 i = 0; i < g; ++i) {
            cin >> a >> b;

            graph[--a].push_back(--b);
            graph[b].push_back(a);
        }

        vector<pair<i32, i32>> monsters(k); // f: vertex s: health
        i32 max_health = 0;
        for (i32 i = 0; i < k; ++i) {
            cin >> a >> b;

            monsters[i] = {a - 1, b};
            max_health = max(max_health, b);
        }

        // dfs
        vector<bool> visited(n);
        deque<i32> stack{0};
        while (!stack.empty()) {
            const i32 u = stack.back();
            stack.pop_back();

            if (visited[u]) continue;

            visited[u] = true;

            for (const i32 v : graph[u]) {
                if (visited[v]) continue;

                stack.push_back(v);
            }
        }

        if (!visited.back()) {
            cout << "-1\n";
            continue;
        }
        fill(visited.begin(), visited.end(), false);

        vector<i32> min_mana(max_health + 1, I32MAX);
        for (i32 i = 1; i <= max_health; ++i) {
            for (const auto [cost, dmg] : spells) {
                min_mana[i] = min(min_mana[i], cost + (dmg >= i ? 0 : min_mana[i - dmg]));
            }
        }

        vector<i32> mana_cost(n);
        for (const auto [vertex, health] : monsters) {
            mana_cost[vertex] += min_mana[health];
        }

        // dijkstra
        const auto compare = [](const pair<i32, i32>& lhs, const pair<i32, i32>& rhs) {
            return lhs.second > rhs.second;
        };

        priority_queue<pair<i32, i32>, vector<pair<i32, i32>>, decltype(compare)> pq{compare}; // f: vertex s: cost
        pq.emplace(0, mana_cost[0]);

        vector<i32> min_cost(n, I32MAX);
        min_cost.front() = mana_cost[0];

        while (!pq.empty()) {
            const auto [curr, cost] = pq.top();
            pq.pop();

            if (visited[curr]) continue;

            visited[curr] = true;

            for (const i32 v : graph[curr]) {
                if (visited[v]) continue;

                const i32 new_cost = cost + mana_cost[v];

                if (new_cost < min_cost[v]) {
                    min_cost[v] = new_cost;
                    pq.emplace(v, new_cost);
                }
            }
        }

        cout << min_cost.back() << '\n';
    }

    return 0;
}