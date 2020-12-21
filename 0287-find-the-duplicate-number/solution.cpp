class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int hare, tortoise;
        hare = tortoise = 0;
        do 
        {
            hare = nums[nums[hare]];
            tortoise = nums[tortoise];
        }while(hare != tortoise);
        
        
        tortoise = 0;
        while(hare != tortoise)
        {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        
        return hare;
        
        
        
    }
};
