class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int space_idx = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (space_idx < spaces.size() && i == spaces[space_idx]) {
                ans += " ";
                space_idx++;
            }
            ans += s[i];
        }

        return ans;
    }
};
