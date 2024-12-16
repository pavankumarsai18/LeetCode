class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<array<int, 2>> num_idx_pairs;
        for (int i = 0; i < nums.size(); ++i) {
            num_idx_pairs.push_back({nums[i], i});
        }

        auto comp = [] (array<int, 2> & a, array<int, 2> & b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] > b[0];
        };

        make_heap(begin(num_idx_pairs), end(num_idx_pairs), comp);

        for (int iter = 0; iter < k; ++iter) {
            pop_heap(begin(num_idx_pairs), end(num_idx_pairs), comp);
            array<int, 2> & pair_ = num_idx_pairs.back();
            pair_[0] *= multiplier;
            nums[pair_[1]] *= multiplier;
            push_heap(begin(num_idx_pairs), end(num_idx_pairs), comp);
        }

        return nums;
    }
};
