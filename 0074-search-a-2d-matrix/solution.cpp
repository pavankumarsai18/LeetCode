class Solution {
private:
    bool binarySearch(vector<int>& nums, int target)
    {
        if(nums.size() == 0)
            return false;
        
        if(nums[0] == target || nums[nums.size() - 1] == target)
            return true;
        
        int hi, lo;
        
        lo = 0;
        hi = nums.size() - 1;
        
        while(hi >= lo)
        {
            int mid = (hi + lo)/2;
            
            if(nums[mid] == target)
            {
                return true;
            }
            else
            {
                if(nums[mid] > target)
                {
                    hi = mid - 1;
                }
                else if(nums[mid] < target)
                {
                    lo = mid + 1;
                }
            }
        }
        
        return false;
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix[0].size();
        
        
        int hi = matrix.size()*n - 1;
        int lo = 0;
        
        
        while(hi >= lo)
        {   
            int mid = (hi + lo)/2;
            
            if(matrix[mid/n][mid%n] == target)
            {
                return true;
            }
            else if(matrix[mid/n][mid%n] > target)
            {
                hi = mid - 1;
            }
            else if(matrix[mid/n][mid%n] < target)
            {
                lo = mid + 1;
            }
            
        }
        return false;
        
    }
};
