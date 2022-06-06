class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> prefix, postfix;
        long long curProduct = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            prefix.push_back(curProduct);
            curProduct *= nums[i];
        }
        
        
        curProduct = 1;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            postfix.push_back(curProduct);
            curProduct *= nums[i];

        }
        
        reverse(postfix.begin(), postfix.end());
        
        vector<int> result;
        
        for(int i = 0; i < nums.size(); i++)
        {
            result.push_back(postfix[i]*prefix[i]);
        }
        
        return result;
    }
};
