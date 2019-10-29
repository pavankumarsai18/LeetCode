class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //YAY!!!!
        //vector<int> temp = nums;
        sort(nums.begin(), nums.end());
        int max_sum_min = 0;
        for(int i = 0; i < nums.size(); i+=2)
        {
            max_sum_min += nums[i];
        }
        
        return max_sum_min;
    }
    
    // -1 0 1 2 3 4 5 6
    // -1 1 3 5
};
