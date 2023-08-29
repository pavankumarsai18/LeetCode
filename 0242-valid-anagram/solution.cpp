class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        const int numChars = 26;
        int charCount[numChars] = {0};

        for (int i = 0; i < s.size(); ++i) {
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }


        for (int i = 0; i < numChars; ++i) {
            if (charCount[i] != 0) return false;
        }

        return true;

    }
};
