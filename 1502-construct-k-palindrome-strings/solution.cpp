class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;

        const int num_chars = 26;
        bool char_parity[num_chars] = {false};
        for (int i = 0; i < s.size(); ++i) {
            char_parity[s[i] - 'a'] = !char_parity[s[i] - 'a'];
        }

        int num_odd_freq = 0;
        for (int i = 0; i < num_chars; ++i) {
            num_odd_freq += char_parity[i];
        }

        return num_odd_freq <= k;
    }
};
