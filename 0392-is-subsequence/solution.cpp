class Solution {
public:
    bool isSubsequence(string s, string t) {
        int s_idx = 0, t_idx = 0;

        while (s_idx != s.size() && t_idx != t.size()) {
            if (s[s_idx] == t[t_idx]) {
                s_idx++;
                t_idx++;
            } else {
                t_idx++;
            }
        }

        return s_idx == s.size();
    }
};
