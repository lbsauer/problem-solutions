// https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes
// 2025/06/03

class Solution {
    enum box_status { CLOSED = 0, OPEN = 1, WAITING = 2, DONE = 3 };
    
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        vector<int> boxes;
        for (const int b : initialBoxes) {
            if (status[b] == OPEN) {
                boxes.push_back(b);
                status[b] = DONE;
            } else {
                status[b] = WAITING;
            }
        }

        int total_candy = 0;
        while (!boxes.empty()) {
            const int b = boxes.back();
            boxes.pop_back();

            total_candy += candies[b];

            for (const int key : keys[b]) {
                if (status[key] == WAITING) {
                    boxes.push_back(key);
                    status[key] = DONE;
                } else {
                    status[key] = status[key] == DONE ? DONE : OPEN;
                }
            }

            for (const int nb : containedBoxes[b]) {
                if (status[nb] == OPEN) {
                    boxes.push_back(nb);
                    status[nb] = DONE;
                } else {
                    status[nb] = status[nb] == DONE ? DONE : WAITING;
                }
            }
        }

        return total_candy;
    }
};