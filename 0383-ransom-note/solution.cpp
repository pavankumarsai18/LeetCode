class Solution {
public:
    vector<int> getCharCount(const string & s) {
        vector<int> charCount(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            charCount[s[i] - 'a']++;
        }
        return charCount;
    }

    bool canConstruct(string ransomNote, string magazine) {
        const int numChars = 26;
        vector<int> ransomCharCount = getCharCount(ransomNote);
        vector<int> magazineCharCount = getCharCount(magazine);

        for (int i = 0; i < numChars; ++i) {
            if (ransomCharCount[i] > magazineCharCount[i]) {
                return false;
            }
        }

        return true;
    }
};
