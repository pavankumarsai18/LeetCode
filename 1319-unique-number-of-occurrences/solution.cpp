class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> numCount;
        for(int i = 0; i < arr.size(); ++i) {
            numCount[arr[i]]++;
        }

        unordered_set<int> uniqueCount;
        for (auto & [key, value] : numCount)
            uniqueCount.insert(value);

        return uniqueCount.size() == numCount.size();
    }
};
