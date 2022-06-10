class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        const int n = s.size();
        int i = 0;
        unordered_map<char, int> lastSeen;
        int ans = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if(lastSeen.find(s[j]) != lastSeen.end())
            {
                i = max(lastSeen[s[j]], i);
            }
            
            ans = max(ans, j - i + 1);
            lastSeen[s[j]] = j + 1;
        }
        
        return ans;
    }
};
