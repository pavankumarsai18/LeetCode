class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int result = 0;
        int countOnes = 0;
        
        for(int bitShift = 31; bitShift >= 0; bitShift--)
        {
            for(int i = 0; i < nums.size(); i++)
            {
                if((nums[i]>>bitShift)&1 == 1)
                    countOnes++;
            }
            if(countOnes > nums.size()/2)
            {
                result += (1)<<bitShift;
            }
            countOnes = 0;
        }
        
        return result;
    }
};
