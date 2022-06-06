class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lo, hi;
        lo = 0; hi = numbers.size()-1;
        
        while(lo < hi)
        {
            if(numbers[lo] + numbers[hi] > target)
            {
                hi--;
            }
            else if(numbers[lo] + numbers[hi] < target)
            {
                lo++;
            }
            else
            {
                return {lo+1, hi+1};
            }
        }
        return vector<int>();
    }
};
