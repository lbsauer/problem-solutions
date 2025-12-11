// https://leetcode.com/problems/vowel-spellchecker
// 2025/09/14

class Solution {
    string& to_lower(string& s) {
        for (char& c : s) {
            c = tolower(c);
        }

        return s;
    }

    string& to_vowel_a(string& s) {
        for (char& c : s) {
            if (c == 'i' || c == 'u' || c == 'e' || c == 'o') c = 'a';
        }

        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());

        unordered_map<string, string> vowel, capitalization;
        for (int i = wordlist.size() - 1; i >= 0; --i) {
            string word = wordlist[i];
            capitalization[to_lower(word)] = wordlist[i];
            vowel[to_vowel_a(word)] = wordlist[i];
        }

        for (string& q : queries) {
            if (exact.contains(q)) continue;

            const auto it1 = capitalization.find(to_lower(q));
            if (it1 != capitalization.end()) {
                q = it1->second;
                continue;
            }

            const auto it2 = vowel.find(to_vowel_a(q));
            if (it2 != vowel.end()) {
                q = it2->second;
                continue;
            }

            q = "";
        }

        return queries;
    }
};