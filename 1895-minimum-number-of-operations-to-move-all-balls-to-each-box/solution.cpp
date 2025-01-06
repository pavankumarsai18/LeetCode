class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        int numLeft = 0, movesLeft = 0;
        int numRight = 0, movesRight = 0;

        for (int i = 0; i < n; ++i) {
            ans[i] += movesLeft;
            numLeft += boxes[i] - '0';
            movesLeft += numLeft;
            
            int j = n -1 - i;
            ans[j] += movesRight;
            numRight += boxes[j] - '0';
            movesRight += numRight;
        }

        return ans;
    }
};
