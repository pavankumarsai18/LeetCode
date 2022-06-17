class Solution {
public:
    void cleanDeque(deque<int>& windowIndices, int index, vector<int> & nums, int k)
    {
        if(windowIndices.size() > 0 && windowIndices.front() == index - k)
        {
            windowIndices.pop_front();
        }
        
        while(windowIndices.size() > 0 && nums[index] > nums[windowIndices.back()])
        {
            windowIndices.pop_back();
        }
    }
    void printDeque(deque<int>  D, vector<int> & nums)
    {
        while(D.size()){
            cout<<nums[D.front()]<< " ";
            D.pop_front();
        }
        cout<<endl;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;
        deque<int> windowIndices;
        int maxIndex = 0;
        int r = 0;
        
        for(r=0;r < k;r++)
        {
            cleanDeque(windowIndices, r, nums, k);
            windowIndices.push_back(r);
            // printDeque(windowIndices, nums);
            if(nums[r] > nums[maxIndex])
                maxIndex = r;
        }
        ans.push_back(nums[maxIndex]);
        
        for(; r < nums.size(); r++)
        {
            cleanDeque(windowIndices, r, nums, k);
            windowIndices.push_back(r);
            
            // printDeque(windowIndices, nums);

            ans.push_back(nums[windowIndices.front()]);
        }
        
        return ans;
        
    }
};
