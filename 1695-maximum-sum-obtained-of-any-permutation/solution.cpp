class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) 
    {
        vector<int> N(nums.size()+1);
        int modVal = 1000000007;
        
        // Get the frequesncy of each item
        for(auto & v: requests)
        {
            int start, end;
            start = v[0];
            end   = v[1];
            
            N[start]++;
            if(end + 1< N.size())
            {
                N[end+1]--;
            }
        }
        
        for(int i = 0; i < N.size(); i++)
        {
            if(i != 0)
            {
                N[i] += N[i-1];
            }
        }
        // get the maximum length of indices
        int indexRange = 0;
        
        for(auto & num: N)
        {
            if(num != 0)
                indexRange++;
        }
        
        // Sort in descending order
        sort(N.begin(), N.end(), greater<int>());
        sort(nums.begin(), nums.end(), greater<int>());
        
        // Result is found by multiplying the value in num with frequency
        int result = 0;
        
        for(int i = 0; i < indexRange; i++)
        {
            long long temp = (N[i]%modVal);
            temp *=(nums[i]%modVal);
            temp %= modVal;
            
            result += static_cast<int>(temp);
            result %= modVal;
        }
        
        return result;
    }
};
