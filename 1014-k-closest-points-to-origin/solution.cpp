class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) 
    {
        vector<vector<int>> result;
        
        if(points.size() == 0)
        {
            return result;
        }
        
        unordered_map<int, vector<vector<int>>> D;
        for(auto & v: points)
        {
            int dist = v[0]*v[0] + v[1]*v[1];
            
            auto itr = D.find(dist);
            if(itr == D.end())
                D[dist] = vector<vector<int>>();
            
            D[dist].push_back(v);
            
        }
        
        priority_queue<int, vector<int>, greater<int>> distances;
        for(auto itr = D.begin(); itr != D.end(); itr++)
        {
            distances.push(itr->first);
        }
        
        int sz = 0;
        while(sz != K)
        {
            int dist = distances.top();
            distances.pop();
            
            for(auto itr = D[dist].begin(); itr != D[dist].end(); itr++)
            {
                if(result.size() == K)
                    return result;
                result.push_back(*itr);
            }
            
            if(result.size() == K)
                    return result;
            sz = result.size();
        }
        
        return result;
        
        
    }
};
