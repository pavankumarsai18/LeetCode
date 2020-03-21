class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
 
        
        unordered_map<int,int> num_count;
        for(auto n: nums)
        {
            auto itr = num_count.find(n);
            if(itr == num_count.end())
            {
                num_count[n] = 1;
            }
            else
            {
                num_count[n]++;
            }
        }
        
        unordered_map<int, vector<int>> count_list;
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            auto i = count_list.find(itr->second);
            if(i == count_list.end())
            {
                vector<int> n;
                n.push_back(itr->first);
                count_list[(itr->second)] = n;
            }
            else
            {
                count_list[(itr->second)].push_back(itr->first);
            }
        }
 
        
        priority_queue<int> h;
        for(auto itr = count_list.begin(); itr != count_list.end(); itr++)
        {
            h.push(itr->first);
        }
    
        vector<int> result;
        
        while(result.size() < k)
        {
            int n = h.top();
            for(auto c: count_list[n])
            {
                
                if(result.size() == k)
                    break;
                result.push_back(c);
            }
            h.pop();
            
        }
        
        return result;
    }
};
