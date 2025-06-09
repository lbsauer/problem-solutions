// https://leetcode.com/problems/minimum-cost-to-convert-string-i
// 2024/11/12

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int dist[26][26];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = i == j ? 0 : INT_MAX;
            }
        }
 
        for (int i = 0; i < original.size(); ++i) {
            const int o = original[i] - 'a';
            const int c = changed[i] - 'a';
 
            dist[o][c] = min(dist[o][c], cost[i]);
        }
 
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (max(dist[i][k], dist[k][j]) == INT_MAX) continue;
 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
 
        long long total = 0;
        for (int i = 0; i < source.size(); ++i) {
            const int d = dist[source[i] - 'a'][target[i] - 'a'];
 
            if (d == INT_MAX) return -1;
 
            total += d;
        }
 
        return total;
    }
};