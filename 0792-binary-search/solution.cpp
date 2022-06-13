class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums[0] == target)
            return 0;
        const int n = nums.size();
        int index = 1;
        while(index < n && nums[index] <= target)
        {
            if(nums[index] == target)
                return index;
            index <<= 1;
            
        }
        
        int lo = index>>1;
        int hi = min(index, n-1);
        while(lo <= hi)
        {
            int mid = lo + (hi - lo)/2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return -1;
        
        
    }
};
