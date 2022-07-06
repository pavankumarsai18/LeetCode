class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
        const int n = nums.size();
        int prefixSum = 0;
        int longestLength = 0;        
        vector<int> seen(2*n + 1, -1);
        
        int index;
        for(int i = 0; i < n; i++)
        {
            prefixSum += (nums[i] == 0)? -1: 1;
            
            index = prefixSum + n;
            
            if(prefixSum == 0)
                longestLength = i+1;
            if(seen[index] != -1)
                longestLength = max(longestLength, i - seen[index]);
            if(seen[index] == -1)
                seen[index] = i;
        }
        
        return longestLength;
        
        
        
    }
};
