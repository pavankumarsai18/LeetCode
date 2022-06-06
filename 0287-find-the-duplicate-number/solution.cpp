class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {   
        
        int tortoise, rabbit;
        tortoise = nums[0];
        rabbit   = nums[0];
        
        do
        {
            tortoise = nums[tortoise];
            rabbit   = nums[nums[rabbit]];
            
        }while(tortoise != rabbit);

        tortoise = nums[0];
        
        while(tortoise != rabbit)
        {
            tortoise = nums[tortoise];
            rabbit   = nums[rabbit];
        }
        
        return tortoise;
    }
};
