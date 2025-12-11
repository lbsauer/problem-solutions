// https://leetcode.com/problems/find-common-elements-between-two-arrays
// 2025/08/04

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums2.begin(), nums2.end());

        int answer1 = 0;
        for (const int n : nums1) {
            answer1 += set.count(n);
        }

        set.clear();
        set.insert(nums1.begin(), nums1.end());

        int answer2 = 0;
        for (const int n : nums2) {
            answer2 += set.count(n);
        }

        return {answer1, answer2};
    }
};