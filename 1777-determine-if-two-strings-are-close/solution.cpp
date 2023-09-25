class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        const int n = word1.size();
        
        int charCount1[26] = {0};
        int charCount2[26] = {0};

        for (int i = 0; i < n; ++i) {
            charCount1[word1[i] - 'a']++;
            charCount2[word2[i] - 'a']++;
        }

        for (int i = 0; i < 26; ++i) {
            if ((charCount1[i] == 0 && charCount2[i] > 0) ||
             (charCount2[i] == 0 && charCount1[i] > 0)) 
                return false;
        }

        sort(charCount1, charCount1 + 26);
        sort(charCount2, charCount2 + 26);

        for (int i = 0; i < 26; ++i) {
            if (charCount1[i] != charCount2[i]) return false;
        }
        return true;
    }
};
