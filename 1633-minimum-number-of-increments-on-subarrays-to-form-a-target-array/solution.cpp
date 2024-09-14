class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int numOps = target[0];

        for(int i = 1; i < target.size(); ++i) {
            int diff = target[i] - target[i - 1];
            if (diff > 0) {
                numOps += diff;
            }
        }
        return numOps;
    }
};
