class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        // Perform DFS
        int result = 0;
        while(target > startValue)
        {
            result++;
            if(target&1 == 1)
            {
                target++;
            }
            else{
                target >>= 1;
            }
        }
        
        return result + startValue - target;
    }
};
