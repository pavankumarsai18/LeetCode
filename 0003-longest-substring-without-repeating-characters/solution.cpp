class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int n = s.size();
        unordered_map<char, int> charCount;
        int left, ans;
        char ch;
        left = ans = 0;
        
        for(int right = 0; right < n; right++)
        {
            ch = s[right];
            charCount[ch]++;
            
            if(charCount.find(ch) == charCount.end()) ans = max(ans, right - left + 1);
            
            while(left <= right && charCount[ch] > 1)
            {
                charCount[s[left]]--;
                if(charCount[s[left]] == 0) charCount.erase(s[left]);
                left++;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};
