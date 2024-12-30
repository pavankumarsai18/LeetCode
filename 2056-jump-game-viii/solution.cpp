class Solution {
private:
    vector<long long> memo;
    vector<int> nextGreater;
    vector<int> nextSmaller;
public:
    long long dfs(int start_idx, vector<int>& nums, vector<int>& costs) {
        if (start_idx == nums.size() - 1) return 0;
        if (memo[start_idx] != -1) {
            return memo[start_idx];
        }
        long long cost = LLONG_MAX;
        if (nextGreater[start_idx] != -1) {
            cost = min(cost, dfs(nextGreater[start_idx], nums, costs) + costs[nextGreater[start_idx]]);
        }

        if(nextSmaller[start_idx] != -1) {
            cost = min(cost, dfs(nextSmaller[start_idx], nums, costs) + costs[nextSmaller[start_idx]]);

        }
        
        return memo[start_idx] = cost;
    }

    long long minCost(vector<int>& nums, vector<int>& costs) {
        memo = vector<long long>(nums.size(), -1);
        nextGreater = vector<int>(nums.size(), -1);
        nextSmaller = vector<int>(nums.size(), -1);

        stack<int> s;
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) s.pop();
            if (!s.empty()) nextGreater[i] = s.top();
            s.push(i);
        }

        s = stack<int>();
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] >= nums[i]) s.pop();
            if (!s.empty()) nextSmaller[i] = s.top();
            s.push(i);
        }

        long long ans =  dfs(0, nums, costs);
        return ans;
    }

};
