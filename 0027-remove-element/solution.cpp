class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int numValOccurances = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                numValOccurances++;
            } else {
                nums[i - numValOccurances] = nums[i];
            }
        }

        for (int i = nums.size() - numValOccurances; i < nums.size(); ++i) {
            nums[i] = val;
        }

        return nums.size() - numValOccurances;
    }
};
