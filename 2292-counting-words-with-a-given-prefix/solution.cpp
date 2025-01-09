class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        const int pref_len = pref.size();
        for (int i = 0; i < words.size(); i++) {
            string & word = words[i];
            if (word.size() < pref_len) {
                continue;
            }
            bool is_prefix = true;
            for (int idx = 0; idx < pref_len; ++idx) {
                if (pref[idx] != word[idx]) {
                    is_prefix = false;
                    break;
                }
            }

            if (is_prefix) {
                ans++;
            }
        }

        return ans;
    }
};
