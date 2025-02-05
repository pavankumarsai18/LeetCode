class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.size() != s2.size()) return false;
        int charCount[26] = {0};
        int num_mismatch = 0;

        for (int i = 0; i < s1.size(); ++i) {
            charCount[s1[i] - 'a']++;
            charCount[s2[i] - 'a']--;
            if (s1[i] != s2[i]) {
                num_mismatch++;
            }
        }

        for (int i = 0; i < 26; ++i) {
            if (charCount[i] != 0) {
                return false;
            }
        }

        return num_mismatch <= 2;
    }
};
