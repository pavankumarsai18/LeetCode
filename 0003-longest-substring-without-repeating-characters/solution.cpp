class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lo, hi;
        int longestSubStr = 0;
        const int n = s.size();
        unordered_map<char, int> charCount;

        lo = 0;
        hi = 0;


        for (; hi < n; hi++) {
            charCount[s[hi] - 'a']++;
            while(lo <= hi && charCount[s[hi] - 'a'] != 1) {
                charCount[s[lo] - 'a']--;
                lo++;
            }
            
            longestSubStr = max(longestSubStr, hi - lo + 1);
 
        }

        return longestSubStr;
    }
};
