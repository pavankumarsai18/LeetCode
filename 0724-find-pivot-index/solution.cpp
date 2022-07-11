class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        const int n = nums.size();
        int totalSum = 0;
        int curSum   = 0;
        for(int i = 0; i < n; i++){totalSum += nums[i];}
        
        int leftSum, rightSum;
        for(int i = 0; i < n; i++)
        {
            leftSum  = curSum;
            curSum   += nums[i];
            rightSum = totalSum - curSum;
            
            if(leftSum == rightSum)
                return i;
        }
        
        return -1;
        
    }
};
