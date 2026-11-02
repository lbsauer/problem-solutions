// https://leetcode.com/problems/friends-of-appropriate-ages
// 2026/01/31

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int freq[121]{};
        for (const int age : ages) {
            ++freq[age];
        }

        partial_sum(begin(freq), end(freq), begin(freq));

        int count = 0;
        for (int i = 1; i <= 120; ++i) {
            count += max(0, (freq[i] - freq[i / 2 + 7] - 1) * (freq[i] - freq[i - 1]));
        }

        return count;
    }
};