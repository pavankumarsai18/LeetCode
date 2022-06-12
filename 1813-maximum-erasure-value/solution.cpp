class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        const int n = nums.size();
        
        int maxSum = 0;
        int sum = 0;
        unordered_set<int> subset;        
        int l, r;
        l = 0; r = 0;
        
        
       for(int r = 0; r < n; r++)
       {
           while(subset.find(nums[r]) != subset.end())
           {
               subset.erase(nums[l]);
               sum -= nums[l];
               l++;
           }
           
           sum += nums[r];
           subset.insert(nums[r]);
           
           maxSum = max(maxSum, sum);
       }
        
        return maxSum;
        
    }
};
