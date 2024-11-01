// https://leetcode.com/problems/integer-to-english-words
// 2024/08/07

class Solution {
public:
    string num_word(int num, const vector<string>& words) {
        string res = "";
        
        if (num >= 100) {
            res += words[num / 100] + " Hundred";
            num %= 100;
        }

        if (num >= 20) {
            if (!res.empty()) res += " ";

            res += words[num / 10 + 18];
            num %= 10;
        }

        if (num > 0) {
            if (!res.empty()) res += " ";

            res += words[num];
        }

        return res;
    }
    
    string numberToWords(int num) {
        const vector<string> words = {
            "Zero",    "One",       "Two",      "Three",
            "Four",    "Five",      "Six",      "Seven",
            "Eight",   "Nine",      "Ten",      "Eleven",
            "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen",
            "Twenty",  "Thirty",    "Forty",    "Fifty",
            "Sixty",   "Seventy",   "Eighty",   "Ninety"
        };

        if (num == 0) return words[0];

        string res = "";

        if (num >= 1'000'000'000) {
            res += words[num / 1'000'000'000] + " Billion";
            num %= 1'000'000'000;
        }

        if (num >= 1'000'000) {
            if (!res.empty()) res += " ";

            res += num_word(num / 1'000'000, words) + " Million";
            num %= 1'000'000;
        }

        if (num >= 1'000) {
            if (!res.empty()) res += " ";

            res += num_word(num / 1'000, words) + " Thousand";
            num %= 1'000;
        }

        if (num > 0) {
            if (!res.empty()) res += " ";
            
            res += num_word(num % 1000, words);
        }

        return res;
    }
};