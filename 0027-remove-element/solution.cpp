class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int num_repeated = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            // cout<<"i "<<i<<endl;
            if(nums[i] == val)
            {
                num_repeated++;
            }
            else if(i != 0)
            {
                int j = i;
                while(j >= 1 && nums[j - 1] == val)
                {
                    // cout<<j<<" j"<<endl;
                    j--;
                }
                swap(nums[j], nums[i]);
            }
        }
        return nums.size() - num_repeated;
        
        
    }
};
