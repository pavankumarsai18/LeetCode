class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur_ones = 0;
        int updated_ones = 0;
        
        for(size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                cur_ones ++;
            }
            else
            {
                // cout<<"index "<<i<<" cur_ones "<<cur_ones<<" updated_ones "<<updated_ones<<endl;
                if(cur_ones > updated_ones)
                {
                    updated_ones = cur_ones;
                }
                cur_ones = 0;
            }
        }
        if(cur_ones > updated_ones)
        {
            updated_ones = cur_ones;
        }
        return updated_ones;
        
    }
};
