class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> result(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                result[i] = 1;
            }
            else{
                result[i] = result[i-1]*nums[i-1];
            }
        }
        
        int R = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            
            if(i == nums.size() - 1)
            {
                R = 1;
            }
            else{
                R *= nums[i+1];
            }
            result[i] *= R;
        }
        
        
    
        return result;
    }
    
};
