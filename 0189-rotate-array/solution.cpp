class Solution {
private:
    void rotateOnce(vector<int>& nums)
    {
        int last = nums[nums.size() - 1];
        int temp = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            int x = nums[i];
            nums[i] = temp;
            temp = x;
        }
        nums[0] = last;
    }

public:
    void rotate(vector<int>& nums, int k) 
    {
        if(nums.size() == 0 || nums.size() == 1)
            return;
        vector<int> Copy = nums;
        int shiftAmt = k;
        // i --> (i + k) %n
        for(int i = 0; i < nums.size(); i++)
        {
            int newIndex = (i + shiftAmt)%nums.size();
            nums[newIndex] = Copy[i];
        }
        
    }
};
