// https://leetcode.com/problems/find-in-mountain-array
// 2024-10-31

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int l, r, m, curr, peak;

        l = 0;
        r = mountainArr.length() - 1;        
        while (l <= r) {
            m = l + (r - l) / 2;

            if (mountainArr.get(m) < mountainArr.get(m + 1)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        peak = l;

        l = 0;
        r = peak;
        while (l <= r) {
            m = l + (r - l) / 2;
            curr = mountainArr.get(m);

            if (curr == target) return m;

            if (curr < target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        l = peak + 1;
        r = mountainArr.length() - 1;
        while (l <= r) {
            m = l + (r - l) / 2;
            curr = mountainArr.get(m);

            if (curr == target) return m;

            if (curr > target) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return -1;
    }
};