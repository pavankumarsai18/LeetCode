class Solution {
public:
    int clumsy(int N) {
        vector<int> nums;
        for(int i  = N; i > 0; i--)
        {
            nums.push_back(i);
        }
        
        for(int i = 0; i < nums.size() - 1; i++)
        {

            if(i%4 == 0)
            {
                if(i+2 < nums.size())
                {
                    
                    nums[i+1] = nums[i]*nums[i+1];
                    nums[i] = 0;
                    nums[i+2] = nums[i+1]/nums[i+2];
                    nums[i+1] = 0;
                    
                    i+= 1;
                }
                else
                {
                    nums[i+1] = nums[i]*nums[i+1];
                    nums[i] = 0;
                }
            }
        }
        
        
        int result = 0;
        int x = 0;
        while(nums[x] == 0)
        {
            x++;
        }
        result = nums[x];
        
        int mul = 1;
        for(int i = x+1; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                ;
            else
            {
                result += mul*nums[i];
                mul *= -1;
            }
        }
        return result;
        
        
    }
};
