// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes
// 2025/06/19

class Solution {
public:
    int maxDistance(string s, int k) {
        if (k + 1 >= s.size()) return s.size();
        
        int max_dist = 0;
        for (int i = 0, lat = 0, lon = 0; i < s.size(); ++i) {
            lat += s[i] == 'N';
            lat -= s[i] == 'S';
            lon += s[i] == 'E';
            lon -= s[i] == 'W';

            max_dist = max(max_dist, abs(lat) + abs(lon) + min(k * 2, i + 1 - abs(lat) - abs(lon)));
        }

        return max_dist;
    }
};