class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        if(nums.size() == 0)
            return 0;
        else
        {
            if(target > nums[nums.size() - 1])
                return nums.size();
            if(target < nums[0])
                return 0;
            
            int hi = nums.size() - 1;
            int lo = 0;

            while(hi >= lo)
            {
                int mid = (hi + lo)/2;

                if(nums[mid] > target)
                {
                    hi = mid - 1;
                }
                else if(nums[mid] < target)
                {
                    lo = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
            
            return (hi + lo)/2 + 1;
        }
    }
};
