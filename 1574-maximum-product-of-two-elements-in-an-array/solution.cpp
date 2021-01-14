class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 2)
            return -1;
        if(nums.size() == 2)
        {
            return (nums[0]-1)*(nums[1]-1);
        }
        
        make_heap(nums.begin(), nums.end());
        int result = nums[0] - 1;
        pop_heap(nums.begin(), nums.end());
        nums.pop_back();
        make_heap(nums.begin(), nums.end());
        result *= (nums[0] - 1);
        return result;
    }
};
