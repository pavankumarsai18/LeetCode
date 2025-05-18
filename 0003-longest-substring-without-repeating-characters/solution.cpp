class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        unordered_set<char> seen;
        int maxLength = 0;

        for (;right < s.size(); ++right) {
            if (seen.find(s[right]) != seen.end()) {
                while (left < right && seen.find(s[right]) != seen.end()) {
                    seen.erase(s[left]);
                    left++;
                }
            }

            seen.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
