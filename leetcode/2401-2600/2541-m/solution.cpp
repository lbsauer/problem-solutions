// https://leetcode.com/problems/minimum-operations-to-make-array-equal-ii
// 2025/06/18

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if (k == 0) return nums1 == nums2 ? 0 : -1;
        
        long long count = 0, delta = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            if (nums1[i] % k != nums2[i] % k) return -1;

            count += abs((nums2[i] - nums1[i]) / k);
            delta += (nums2[i] - nums1[i]) / k;
        }

        return delta == 0 ? count / 2 : -1;
    }
};