class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        // sum = 2a + 2b + 2c + 2d + 2e + ..... + z
        // 1 + 1 = 0
        // use bits
        
        int result = 0;

        for(int j = 31; j >= 0; j--)
        {
            int b = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                b += (nums[i]>>j)&1;
                b %= 2;
            }
            result |= b<<j;
        }

        return result;
    }
};
