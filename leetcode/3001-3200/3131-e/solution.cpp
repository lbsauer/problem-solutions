// https://leetcode.com/problems/find-the-integer-added-to-array-i
// 2025/08/29

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        return *min_element(nums2.begin(), nums2.end()) - *min_element(nums1.begin(), nums1.end());
    }
};