// https://leetcode.com/problems/boats-to-save-people
// 2024/05/04

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        std::sort(people.begin(), people.end());

        int l = 0;
        int r = people.size();
        while (l <= --r) {
            if (people[l] + people[r] <= limit) ++l;
        }

        return people.size() - r - 1;
    }
};