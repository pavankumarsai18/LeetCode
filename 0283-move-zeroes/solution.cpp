class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        // int count = 0;
        // for(int i = 0; i < nums.size(); i++)
        //     if(nums[i] == 0)
        //         count++;
        
        // 0 1 0 3 12
        
        // 1 0 0 3 12
        // 1 3 12 0 0
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] != 0)
        //     {
        //         int j = i;
        //         while(j >= 1 && nums[j] != 0 && nums[j - 1] == 0)
        //         {
        //             std::swap(nums[j], nums[j - 1]);
        //             j --;
        //         }
        //     }
        // }
        
        int last_zero = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
                nums[last_zero++] = nums[i];
        }
        for(int i = last_zero; i < nums.size(); i++)
            nums[i] = 0;
        
        
    }
};
