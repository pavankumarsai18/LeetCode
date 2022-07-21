class Solution {
public:
    int findPairs(vector<int>& nums, int k) 
    {
        unordered_set<int> seen;
        unordered_set<int> used;
        int cur, target;
        
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            cur = nums[i];
            target = cur - k;
            
            if(seen.find(target) != seen.end() && used.find(cur-k) == used.end())
            {
                used.insert(cur - k);
                // cout<<cur<<" "<<target<<endl;
                ans++;
            }
            
            target = cur + k;
            if(seen.find(target) != seen.end() && used.find(cur) == used.end())
            {
                used.insert(cur);
                // cout<<cur<<" "<<target<<endl;
                ans++;
            }
            
            
            seen.insert(cur);
        }
        
        return ans;
        
    }
};
