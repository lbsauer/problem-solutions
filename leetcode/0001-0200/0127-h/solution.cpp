// https://leetcode.com/problems/word-ladder
// 2024/08/15

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words{wordList.begin(), wordList.end()};
        words.erase(beginWord);

        if (!words.count(endWord)) return 0;

        deque<pair<string, int>> queue{{beginWord, 0}};
        while (!queue.empty()) {
            auto [word, count] = queue.front();
            queue.pop_front();

            if (word == endWord) return count + 1;

            for (int i = 0; i < word.length(); ++i) {
                const char original = word[i];
                
                for (word[i] = 'a'; word[i] <= 'z'; ++word[i]) {
                    if (!words.count(word)) continue;

                    queue.emplace_back(word, count + 1);
                    words.erase(word);
                }

                word[i] = original;
            }
        }

        return 0;
    }
};