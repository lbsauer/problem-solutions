// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
// 2024/05/08

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        int i = 0;
        int num;

        while (i < nums.size()) {
            int j = i;
            num = nums[i];
            while (i < nums.size() && nums[i] == num) {
                if (i - j < 2) {
                    nums[k++] = num;
                }
                ++i;
            }
        }

        return k;
    }
};