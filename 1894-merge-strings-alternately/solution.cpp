class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";

        for(int i = 0; i < min(word1.size(),word2.size()); ++i) {
            ans += word1[i];
            ans += word2[i];
        }

        if (word1.size() < word2.size()) {
            ans += word2.substr(word1.size());
        } else if (word2.size() < word1.size()) {
            ans += word1.substr(word2.size());
        }

        return ans;
    }
};
