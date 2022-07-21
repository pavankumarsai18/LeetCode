class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) 
    {        
        const int n = nums.size();
        
        long sum = 0;    
        int ans = n + 1;
        
        // monotonic deque
        deque<pair<long, int>> Q;
        bool contracted = false;
        
        for(int right = 0; right < n; right++)
        {
            sum += nums[right];
            
            if(sum >= k) ans = min(ans, right+1);
            
            pair<long, int> cur = {INT_MIN, INT_MIN};
            contracted = false;
            
            
            // Try to contract the window
            // We contract the window when
            // after removing the left (first item) 
            // will still have sum greater than k
            while(!Q.empty() && sum - Q.front().first >= k)
            {
                contracted = true;
                cur = Q.front(); Q.pop_front();
            }
            
            // Check if we have contracted the window
            if(contracted)
            {
                // Update the ans
                ans = min(ans, right - cur.second);
            }
            
            // Maintain montonic deque pop from back till back is less than sum
            while(!Q.empty() && Q.back().first >= sum)
            {
                Q.pop_back();
            }
            
            // Push the sum, right
            Q.push_back({sum, right});
            
        }
        
        // if the ans is n+1 (impossible) then return -1 else return ans
        return (ans > n)? -1: ans;
        
        
    }
};
