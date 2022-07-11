class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) 
    {
        const int n = arr.size();
        const int windowSize = 2*k + 1;
        vector<int> ans(n, -1);

        if(windowSize > n)
            return ans;
        
        int right, left, mid;
        long long sum = 0LL;
        left = 0;
        
        for(int right = 0; right < n;)
        {
            if(right > 0)
            {
                sum += (arr[right++] - arr[left++]);
                ans[mid++] = sum/windowSize;

            }
            else
            {
                while(right < windowSize){sum += arr[right++];}
                mid = right - k - 1;
                ans[mid++] = sum/windowSize;
            }
        }
        return ans;
        
    }
};
