class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        
        if(nums.size() == 0)
        {   
            string item = to_string(lower);
            if(lower != upper)
                item += "->" + to_string(upper);
            
            return {item};
        }
        
        vector<string> result;
        int lo = 0;
        int hi = 0;
        bool loFound = false;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= lower && loFound == false)
            {
                lo = i;
                loFound = true;
            }
            
            if(nums[i] <= upper)
            {
                hi = i;
            }
        }
        
        
        
        int curIndex = lo;
        int curNum = lower;
        
        for(int curNum = lower; curNum <= upper; curNum++)
        {
            if(curIndex > hi)
                    break;
            if(curNum != nums[curIndex])
            {

                string item = to_string(curNum);
                if(curNum != nums[curIndex]-1)
                    item += "->" + to_string(nums[curIndex]-1);
                
                result.push_back(item);
                curNum = nums[curIndex];
            }
            curIndex ++;
        }
        
        if(nums[hi] < upper)
        {
            string item = to_string(nums[hi]+1);
            if(nums[hi]+1 != upper)
                item += "->" + to_string(upper);
            result.push_back(item);

        }
        
        
        return result;
        
        
    }
};
