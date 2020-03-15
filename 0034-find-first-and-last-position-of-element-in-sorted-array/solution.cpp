class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if(nums.size() == 0)
        {
            vector<int> result = {-1, -1};
            return result;
        }
        if(nums.size() == 1)
        {
            if(nums[0] == target)
            {
                vector<int> result = {0,0};
                return  result;
            }
            else
            {
                vector<int> result = {-1,-1};
                return  result;
            }
        }
        
        int hi = nums.size() - 1;
        int lo = 0;
        
        int ind = -1;
        
        while(hi >= lo)
        {
            int mid = (hi + lo)/2;

            
            if(nums[mid] > target)
            {
                hi = mid -1;    
            }
            else if(nums[mid] < target)
            {
                lo = mid + 1;
            }
            else
            {
                ind = mid;
                break;
            }
        }
        
        if(ind == -1)
        {
            vector<int> result= {-1, -1};
            return result;
        }
        
        int start = ind;
        int end = ind;
        
        while(start >= 0 && nums[start] == target)
            start--;
        start++;
        while(end < nums.size() && nums[end] == target)
            end++;
        end--;
        
        vector<int> result = {start, end};
        return result;
        
    }
};
