class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int lo, hi;
        lo = 0; hi = numbers.size()-1;
        
        vector<int> result;
        while(lo < hi)
        {
            if(numbers[lo] + numbers[hi] == target)
            {
                result.push_back(lo + 1);
                result.push_back(hi + 1);
                return result;
            }
            else if(numbers[lo] + numbers[hi] < target)
            {
                lo++;
            }
            else
            {
                hi--;
            }
        }
        
        return vector<int>();
    }
};
