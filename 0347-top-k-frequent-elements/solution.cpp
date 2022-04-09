class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> numCount;
        for(auto & n: nums)
        {
            numCount[n]++;
        }
        priority_queue<pair<int, int>> Q;
        for(auto item:numCount)
        {
            Q.push({item.second, item.first});
        }
        vector<int> result;
        for(int i =0;i<k;i++)
        {
            result.push_back(Q.top().second);Q.pop();
        }
        return result;
    }
};
