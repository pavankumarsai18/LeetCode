class Solution {
public:
    vector<int> diff(const unordered_set<int>& A, const unordered_set<int>& B) {
        vector<int> diffA;
        for (auto & num : A) {
            if (B.find(num) == B.end()) {
                diffA.push_back(num);
            }
        }
        return diffA;
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        const unordered_set<int> uniqueNums1(nums1.begin(), nums1.end());
        const unordered_set<int> uniqueNums2(nums2.begin(), nums2.end());
        
        return {diff(uniqueNums1, uniqueNums2), diff(uniqueNums2, uniqueNums1)};
    }
};
