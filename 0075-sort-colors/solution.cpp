class Solution {
public:
    void sortColors(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
                ones++;
            if(nums[i] == 2)
                twos++;
        }
        
        for(int i = 0; i < nums.size() - ones - twos; i++)
        {
            nums[i] = 0;
        }
        for(int i = nums.size() - ones - twos; i < nums.size() - twos; i++)
        {
            nums[i] = 1;
        }
        for(int i = nums.size() - twos; i < nums.size(); i++)
        {
            nums[i] = 2;
        }
        
    }
};
