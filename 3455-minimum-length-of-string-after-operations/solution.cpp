class Solution {
public:
    int minimumLength(string s) {
        int char_count[26] = {0};
        for (size_t i = 0; i < s.size(); ++i) {
            char_count[s[i] - 'a']++;
        }
        int length_after_ops = 0;
        for (size_t i = 0; i < 26; ++i) {
            if (char_count[i]) {
                if (char_count[i] & 1) {
                    char_count[i] = 1;
                } else {
                    char_count[i] = 2;
                }
            }
            length_after_ops += char_count[i];    
        }

        return length_after_ops;
    }
};
