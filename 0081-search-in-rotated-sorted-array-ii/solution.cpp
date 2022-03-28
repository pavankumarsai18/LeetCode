class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        
        if(nums.size() <= 10)
        {
            for(int i = 0; i < nums.size(); i++)
                if(nums[i] == target)
                    return true;
            return false;
        }
        int lo = 0;
        int hi = nums.size() - 1;

        while(hi >= lo)
        {
            
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] == target || nums[lo] == target || nums[hi] == target)
                return true;
            
            while(lo < hi && nums[lo] == nums[mid] && nums[mid] == nums[hi])
            {
                lo++; hi--;
            }
            
            if(nums[lo] == target || nums[hi] == target)
                return true;
            
            if(nums[lo] <= nums[mid])
            {
                
                if(nums[lo] <= target && nums[mid]>target)
                    hi = mid - 1;
                else
                    lo = mid +1;
            }
            else
            {
                if(nums[hi] >= target && nums[mid] < target)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            
        }
        return false;
    }
};
