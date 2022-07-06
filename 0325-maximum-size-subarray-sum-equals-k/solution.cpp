class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        long long prefixSum = 0;
        int longestLength = 0;
        
        unordered_map<long long, int> seen;
        
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            
            if(prefixSum == k)
            {
                longestLength = (i+1);
            }
            
            if(seen.find(prefixSum - k) != seen.end())
            {
                longestLength = max(longestLength, i - seen[prefixSum-k]);
            }
            
            if(seen.find(prefixSum) == seen.end())
            {
                seen[prefixSum] = i;
            }
        }
        
        return longestLength;
    }
};
