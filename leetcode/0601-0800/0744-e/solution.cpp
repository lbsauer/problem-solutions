// https://leetcode.com/problems/find-smallest-letter-greater-than-target
// 2026/01/31

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const auto it = upper_bound(letters.begin(), letters.end(), target);
        return it == letters.end() ? letters[0] : *it;
    }
};