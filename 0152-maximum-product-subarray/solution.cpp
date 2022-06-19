class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        const int n = nums.size(); 
        
        if(n == 1)
            return nums[0];
        
        // long long maxProduct[n+1];
        // long long minProduct[n+1];
        long long ans = INT_MIN;
        
        // maxProduct[0] = 1;
        // minProduct[0] = 1;
        
        long long maxProduct = 1;
        long long minProduct = 1;
        
        for(int i = 0; i < n; i++)
        {
            long long num = nums[i];
            if(num == 0)
            {
                // maxProduct[i+1] = 0;
                // minProduct[i+1] = 1;
                maxProduct = 0;
                minProduct = 1;
            }
            else if(num < 0)
            {
                // maxProduct[i+1] = num*minProduct[i];
                long long prevMaxProduct = maxProduct;
                maxProduct = num*minProduct;
                // minProduct[i+1] = min(num,min(maxProduct[i]*num, 1LL));
                minProduct = min(num, min(prevMaxProduct*num, 1LL));
            }
            else
            {
                long long prevMinProduct = minProduct;

                // maxProduct[i+1] = max(maxProduct[i]*num, max(num, 1LL));
                maxProduct = max(maxProduct*num, max(num, 1LL));
                
                // minProduct[i+1] = min(minProduct[i]*num, 1LL);
                minProduct = min(minProduct*num, 1LL);
            }
            ans = max(maxProduct, ans);
        }
        
        // int ans = maxProduct[1];
        // for(int i = 1; i <= n; i++)
        // {
        //     if(ans < maxProduct[i])
        //         ans = maxProduct[i];
        // }
        
        return (int)ans;
    }
};
