class Solution {
public:
    int findTheLongestSubstring(string s) {
        int charMap[26] = {0};
        charMap['a' - 'a'] = 1;
        charMap['e' - 'a'] = 2;
        charMap['i' - 'a'] = 4;
        charMap['o' - 'a'] = 8;
        charMap['u' - 'a'] = 16;


        vector<int> mp(32, -1);
        int max_length = 0;
        int prefixXor = 0;

        for (int i = 0; i < s.size(); ++i) {
            prefixXor ^= charMap[s[i] - 'a'];
            if (mp[prefixXor] == -1 && prefixXor != 0) mp[prefixXor] = i;

            max_length = max(max_length, i - mp[prefixXor]);
        }

        return max_length;
    }
};
