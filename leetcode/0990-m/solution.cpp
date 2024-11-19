// https://leetcode.com/problems/satisfiability-of-equality-equations
// 2024-11-16

class Solution {
    int find(vector<int>& sets, int x) {
        return sets[x] < 0 ? x : sets[x] = find(sets, sets[x]);
    }

    void unite(vector<int>& sets, int x, int y) {
        x = find(sets, x);
        y = find(sets, y);

        if (x == y) return;

        if (sets[x] > sets[y]) swap(x, y);

        sets[x] += sets[y];
        sets[y] = x;
    }

    bool same(vector<int>& sets, int x, int y) {
        return find(sets, x) == find(sets, y);
    }

public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> sets(26, -1);
        for (const string& e : equations) {
            if (e[1] == '=') unite(sets, e[0] - 'a', e[3] - 'a');
        }

        return none_of(equations.begin(), equations.end(), [&](const string& e) {
            return e[1] == '!' && same(sets, e[0] - 'a', e[3] - 'a');
        });
    }
};