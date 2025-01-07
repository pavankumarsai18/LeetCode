class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        vector<bool> isSubStr(words.size(), false);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                string & word1 = words[i];
                string & word2 = words[j];
                if (word1.find(word2) != string::npos) {
                    isSubStr[j] = true;
                } else if (word2.find(word1) != string::npos) {
                    isSubStr[i] = true;
                }
            }
        }

        for (int i = 0; i < isSubStr.size(); ++i) {
            if (isSubStr[i] == true) {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
