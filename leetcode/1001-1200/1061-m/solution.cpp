// https://leetcode.com/problems/lexicographically-smallest-equivalent-string
// 2025/06/05

class Solution {
    template<size_t size>
    char find(array<char, size>& sets, char c) {
        return sets[c - 'a'] == c ? c
            : sets[c - 'a'] = find(sets, sets[c - 'a']);
    }

    template<size_t size>
    void unite(array<char, size>& sets, char a, char b) {
        a = find(sets, a);
        b = find(sets, b);

        sets[a - 'a'] = min(a, b);
        sets[b - 'a'] = min(a, b);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        array<char, 26> sets;
        iota(sets.begin(), sets.end(), 'a');

        for (int i = 0; i < s1.size(); ++i) {
            unite(sets, s1[i], s2[i]);
        }

        for (char& c : baseStr) {
            c = find(sets, c);
        }

        return baseStr;
    }
};