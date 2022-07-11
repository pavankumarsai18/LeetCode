class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        const int n = nums.size();
        vector<int> ans(2, -1);
        
        if(n == 0) return ans;
        
        int lo, hi, mid;
        lo = 0; hi = n-1;
        
        while(lo < hi)
        {
            mid = lo + ((hi - lo)>>1);
            
            if(nums[mid] > target) hi = mid - 1;
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        
        if(nums[lo] != target) return ans;
        
        ans[0] = lo;
        
        hi = n - 1;
        while(lo < hi)
        {
            mid = lo + ((hi - lo + 1)>>1);
            
            if(nums[mid] < target) lo = mid + 1;
            else if(nums[mid] > target) hi = mid - 1;
            else lo = mid;
        }
        
        ans[1] = lo;
        return ans;
    }
};
