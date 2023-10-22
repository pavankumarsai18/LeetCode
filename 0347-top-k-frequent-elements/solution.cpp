class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> numCount;
        vector<int> frequencies;

        for (int i = 0; i < nums.size(); ++i) {
            if (numCount.find(nums[i]) == numCount.end()) frequencies.push_back(nums[i]);
            numCount[nums[i]]++;
        }


        auto cmp = [&numCount](auto lhs, auto rhs){ return numCount[lhs] < numCount[rhs];};


        std::make_heap (frequencies.begin(),frequencies.end(), cmp);

        vector<int> ans;
        while(ans.size() != k) {
            std::pop_heap(frequencies.begin(), frequencies.end(), cmp);
            ans.push_back(frequencies.back());
            frequencies.pop_back();
        }

        return ans;
    }
};
