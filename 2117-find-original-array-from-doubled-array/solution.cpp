class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) 
    {
        if((changed.size()&2) == 1) return {};
        
        sort(changed.begin(), changed.end());
        
        
        
        vector<int> ans;
        
        
        unordered_map<int, int> freq;
        for(int num: changed)
        {
            freq[num]++;
        }
        
        
        for(int num: changed)
        {
            if(freq[num])
            {
                freq[num]--;
                if(freq[num*2] > 0)
                {
                    freq[num*2]--;
                    ans.push_back(num);
                }
                else
                {
                    return {};
                }
            }
        }
        
        return ans;
        
    }
};
