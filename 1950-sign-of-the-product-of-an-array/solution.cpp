class Solution {
public:
    int arraySign(vector<int>& nums) 
    {
        bool isNeg = false;
        for(int num: nums)
        {
            if(!num&(-1))
            {
                return 0;
            }
            if(num >> 31)
            {
                isNeg = isNeg ^ true;
            }
        }
        
        return (isNeg)? -1 : 1;
    }
};
