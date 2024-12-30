class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int prev_group = -1;
        for (int i = 0; i < words.size(); ++i) {
            if (groups[i] != prev_group) {
                ans.push_back(words[i]);
                prev_group = groups[i];
            }
        }

        return ans;

    }
};
