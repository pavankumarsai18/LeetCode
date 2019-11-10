class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int temp_size = 0;
        int max_size = 0;
        for(int i = 0; i < nums.size();i++)
        {
            if(nums[i] == 1)
            {
                temp_size ++;

                if(max_size < temp_size)
                    max_size = temp_size;
            }
            else
            {
                temp_size = 0;
            }
        }
        
        return max_size;
    }
};
