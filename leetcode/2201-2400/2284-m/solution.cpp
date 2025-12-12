// https://leetcode.com/problems/sender-with-largest-word-count
// 2025/11/22

class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> freq;

        int max_words = 0, max_pos = 0;
        for (int i = 0; i < senders.size(); ++i) {
            int& words = freq[senders[i]];
            words += count(messages[i].begin(), messages[i].end(), ' ') + 1;

            if (words > max_words || (words == max_words) && senders[i] > senders[max_pos]) {
                max_words = words;
                max_pos = i;
            }
        }

        return senders[max_pos];
    }
};