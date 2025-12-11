// https://leetcode.com/problems/maximum-matching-of-players-with-trainers
// 2025/07/15

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0;
        for (int j = 0; i < players.size() && j < trainers.size(); ++j) {
            i += players[i] <= trainers[j];
        }

        return i;
    }
};