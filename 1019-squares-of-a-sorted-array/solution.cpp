class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        // O(n) two pointer
        
        int startIndex = 0;
        int endIndex = nums.size() - 1;
        vector<int> result;
        
        while(startIndex <= endIndex)
        {
            int first = nums[startIndex]*nums[startIndex];
            int last = nums[endIndex]*nums[endIndex];
            
            if(first > last)
            {
                result.push_back(first);
                startIndex++;
            }
            else if(last > first)
            {
                result.push_back(last);
                endIndex--;
            }
            else
            {
                if(startIndex == endIndex){
                     result.push_back(last);
                }
                else{
                    result.push_back(first);
                    result.push_back(last);
                }
                startIndex++;
                endIndex--;
            }
        }
        
        for(size_t i = 0; i < result.size()/2; i++)
        {
            int temp = result[i];
            result[i] = result[result.size() - 1 - i];
            result[result.size() - 1 - i] = temp;
        }
        return result;
        
        
    }
};
