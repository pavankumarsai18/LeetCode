class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> deltaArray(nums.size() + 1, 0);

        for (int i = 0; i < queries.size(); ++i) {
            deltaArray[queries[i][0]]++;
            deltaArray[queries[i][1] + 1]--;
        }

        vector<int> operationCounts;
        int currentOperations = 0;
        for (int delta: deltaArray) {
            currentOperations += delta;
            operationCounts.push_back(currentOperations);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (operationCounts[i] < nums[i]) {
                return false;
            }
        }

        return true;

    }
};
