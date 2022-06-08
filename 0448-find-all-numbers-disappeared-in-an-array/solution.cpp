class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        const int n = nums.size();    

        for(int index = 0; index < n; index++)
        {
            int val = abs(nums[index]);
            
            if(nums[val-1] > 0)
            {
                nums[val - 1] *= -1;
            }
        }
        
        vector<int> result;
        for(int num = 1; num <= n; num++)
        {
            if(nums[num-1] > 0)
                result.push_back(num);
        }
        
        return result;
    }
};
