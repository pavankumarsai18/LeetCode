class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> num_count;
        for (int & num: nums) {
            num_count[num]++;
        }
        
        int sum = 0;
        for (auto & [num, count]: num_count) {
            if (count == 1) {
                sum += num;
            }
        }
        
        return sum;
    }
};
