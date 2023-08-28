class Solution {
public:
    int partitionString(string s) {
        bool unique_chars[26]{0};
        int numSubStrings = 1;

        for (int i = 0; i < s.size(); i++) {
            if (unique_chars[s[i] - 'a']) {
                numSubStrings++;
                std::fill(std::begin(unique_chars), std::end(unique_chars), 0);
            }
            unique_chars[s[i] - 'a'] = 1;
        }

        return numSubStrings;
    }
};
