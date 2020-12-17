class Solution {
private:
    void printArr(vector<int>& nums)
    {
        for(auto & n: nums)
            cout<<n<<" ";
        cout<<endl;
    }
public:
    int removeElement(vector<int>& nums, int val) {

        int result = 0;
        int endIndex = nums.size() - 1;
        int curIndex = 0;
 
        for(; curIndex <= endIndex; curIndex++)
        {
            while(endIndex >= 0 && nums[endIndex] == val)
            {
                result--;
                endIndex--;    
            }
            if(endIndex < 0)
            {
                break;
            }
            
            if(nums[curIndex] == val)
            {
                result --;
                swap(nums[curIndex], nums[endIndex]);
                endIndex--;
            }
            while(endIndex >= 0 && nums[endIndex] == val)
            {
                result--;
                endIndex--;    
            }
            if(endIndex < 0)
            {
                break;
            }
            // cout<<"curIndex "<<curIndex<<endl;
            // cout<<"endIndex "<<endIndex<<endl;
            // printArr(nums);
        }
        result += nums.size();
        return result;
        
    }
};
