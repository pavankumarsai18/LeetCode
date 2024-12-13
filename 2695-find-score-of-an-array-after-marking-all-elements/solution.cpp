class Solution {
public:
    long long findScore(vector<int>& nums) {
        const int length = nums.size();
        vector<bool> marked(length, false);
        vector<array<int, 2>> num_index_pairs;

        for(int i = 0; i < length; ++i) {
            num_index_pairs.push_back({nums[i], i});
        }

        auto compare = [](const std::array<int, 2>& a, 
                const std::array<int, 2>& b) {
            if (a[0] > b[0]) {
                return true;
            } else if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return false;
        };

        make_heap(num_index_pairs.begin(), num_index_pairs.end(), compare);

        long long score = 0LL;
        while (!num_index_pairs.empty()) {
            pop_heap(num_index_pairs.begin(), num_index_pairs.end(),
                        compare);
            int value = num_index_pairs.back()[0];
            int index = num_index_pairs.back()[1];
            if (!marked[index]) {

                // cout << value << " " << index << endl;
                score += value;
                marked[index] = true;
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < length) {
                    marked[index + 1] = true;
                }
            }

            num_index_pairs.pop_back();
        }

        return score;
    }
};
