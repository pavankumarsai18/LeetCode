class Solution {
private:
    void printArr(vector<int>& nums)
    {
        for(auto n: nums)
        {
            cout<<n<<" ";
        }
        cout<<endl;
    }
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return static_cast<int>(nums.size());
        
        int startIndex = 0;
        int endIndex = 0;
        int maxValue = nums[nums.size() - 1];
        
        while(endIndex < nums.size() && startIndex < nums.size())
        {
            // printArr(nums);
            int value = nums[startIndex];
            // cout<<"value "<<value<<endl;
            // cout<<"startIndex "<<startIndex<<endl;
            while(endIndex < nums.size() && value == nums[endIndex])
            {
                endIndex++;
            }
            // cout<<"endIndex "<<endIndex<<endl;
            
            if(endIndex < nums.size() && (startIndex + 1 < nums.size()))
            {
                if(nums[startIndex + 1] != nums[endIndex]){
                    swap(nums[startIndex+1], nums[endIndex]);
                    endIndex++;
                }
            }
            startIndex++;
        }
       
        int result = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            result++;
            if(nums[i] == maxValue)
            {
                break;
            }
        }
        return result;
        
        
    }
};
