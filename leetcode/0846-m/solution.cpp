// https://leetcode.com/problems/hand-of-straights
// 2024/06/06

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        if (groupSize == 1) return true;

        map<int, int> counts;
        for (int card : hand) {
            ++counts[card];
        }

        if (counts.size() == 1) return false;

        auto it = counts.begin();
        while (it != counts.end()) {
            int count = it->second;
            int prev = it->first;
            auto it2 = ++it;

            if (count < 0) return false;
            if (count == 0) continue;

            for (int i = 1; i < groupSize; ++i, ++it2) {
                if (it2->first != prev + 1) return false;

                it2->second -= count;
                ++prev;
            }
        }

        return true;
    }
};