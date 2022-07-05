class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> out(n,1);
        if(n==1) return 1;
        if(n==0) return 0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                out[i] = out[i-1]+1;
            }
            else if(nums[i]-nums[i-1]==0){
                out[i] = out[i-1];
            }
        }
        return *max_element(out.begin(),out.end());
    }
};
