class Solution {
private:
    bool check(vector<int>& nums, int k, double mid)
    {
        double curSum, prevSum, minSum;
        curSum = prevSum = minSum = 0;
        
        for(int i = 0; i < k; i++){curSum += nums[i] - mid;}
        
        if(curSum >= 0) return true;
        
        for(int i = k; i < nums.size(); i++)
        {
            curSum  += nums[i]   - mid;
            prevSum += nums[i-k] - mid;
            
            minSum = min(prevSum, minSum);
            if(curSum >= minSum)
                return true;
        }
        return false;
    }
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        const int n      = nums.size();        
        const double eps = 0.00001;
        
        double lo   = nums[0];
        double hi   = nums[0];
        double mid;
        
        for(int i = 0; i < n; i++)
        {
            lo = min(lo, nums[i]*1.0);
            hi = max(hi, nums[i]*1.0);
        }
        
        while(hi - lo >= eps)
        {
            mid = (hi+lo)/2;
            if(check(nums, k, mid)) lo = mid; 
            else hi = mid;
        }
        
        return hi;
    }
};
