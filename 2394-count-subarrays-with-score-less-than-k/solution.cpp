class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        const int n = nums.size();
        long long windowSum = 0LL;
        long long numSubArrays = 0LL;
        
        int left = 0;
        for(int right = 0; right < n; right++)
        {
            windowSum += nums[right];
            while(left <= right && windowSum*(right-left+1) >= k)
            {
                windowSum -= nums[left++];
            }
            
            numSubArrays += (right-left+1);
            
        }
        
        return numSubArrays;
        
        
    }
};
