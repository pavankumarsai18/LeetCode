class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        
        int ptr1 = 0;
        int ptr2 = 0;
        
        while(ptr1 < nums.size() && ptr2 < nums.size())
        {
            int curVal = nums[ptr2];
            int count = 0;
            // cout<<"ptr1 "<<ptr1<<" ptr2 "<<ptr2<<endl;
            while(ptr2 < nums.size() && ptr1 < nums.size() && nums[ptr2] == curVal)
            {
                if(count < 2)
                {
                    nums[ptr1] = nums[ptr2];
                    ptr1++;
                    ptr2++;
                    count++;
                }
                else{
                    break;
                }
            }
            
            while(ptr2 < nums.size() && nums[ptr2] == curVal)
            {
                ptr2++;
            }
            
            // if(ptr1 < nums.size())
            //     ptr1++;
        }
        
        return ptr1;

        
    }
};
