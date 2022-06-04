class Solution {
public:
    
    vector<int> majorityElement(vector<int>& nums) 
    {
        const int n = nums.size();
        int candidate1, candidate2, count1, count2;
        count1 = count2 = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(candidate1 == nums[i])
            {
                count1++;
            }
            else if(candidate2 == nums[i])
            {
                count2++;
            }
            else if(count1 == 0)
            {
                candidate1 = nums[i];
                count1++;
            }
            else if(count2 == 0)
            {
                candidate2 = nums[i];
                count2++;
            }
            else
            {
                count1--; count2--;
            }
        }
        
        vector<int> ans;
        count1 = count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == candidate1)
                count1++;
            else if(nums[i] == candidate2)
                count2++;
        }
        
        if(count1 > n/3)
            ans.push_back(candidate1);
        if(count2 > n/3)
            ans.push_back(candidate2);
        
        return ans;
    }
};
