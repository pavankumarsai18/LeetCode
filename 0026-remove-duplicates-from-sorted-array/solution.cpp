class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int numDuplicate = 0;
        int curVal = nums[0];
        int idx = 0;
        while (idx < nums.size()) {
            curVal = nums[idx];
            while (idx + 1 < nums.size() && curVal == nums[idx + 1]) {
                idx++;
                numDuplicate++;
            }
            if (idx < nums.size()) {
                nums[idx - numDuplicate] = nums[idx];
            }
            idx++;
      
        }

        return nums.size() - numDuplicate;


    }
};
