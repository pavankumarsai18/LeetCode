class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> num_count;
        
        for(int i = 0; i < nums.size(); i++)
        {            
            num_count[nums[i]]++;
        }
        
        auto cmp = [&num_count](int & a, int & b){return num_count[a] < num_count[b];};
        
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for(auto [num, count]: num_count)
        {
            pq.push(num);
        }
        
        vector<int> result;
        while(result.size() < k && pq.size() > 0)
        {
            result.push_back(pq.top());
            pq.pop();
        }
        
        return result;
        
    }
};
