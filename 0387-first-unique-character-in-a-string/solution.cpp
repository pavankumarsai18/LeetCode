class Solution {
public:
    int firstUniqChar(string s) {
        vector<pair<int, int>> charCount(26, {0,-1});
        
        int index;
        for(int i = 0; i < s.size(); i++)
        {
            index = s[i] - 'a';
            
            charCount[index].first = charCount[index].first + 1;
            charCount[index].second = i;
        }
        
        
        int ans = s.size();
        for(int ch = 0; ch < 26; ch++)
        {
            if(charCount[ch].first == 1 && charCount[ch].second < ans)
            {
                ans = charCount[ch].second;
            }
        }
        
        return (ans == s.size())? -1: ans;
        
        
    }
};
