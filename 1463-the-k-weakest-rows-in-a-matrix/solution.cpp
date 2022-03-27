class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        
        auto compare = [&](pair<int, int>& pair1, pair<int, int> & pair2)
        {
            int count1 = pair1.first;
            int count2 = pair2.first;
            int index1 = pair1.second;
            int index2 = pair2.second;
            
            if(count1 < count2)
                return false;
            else if(count1 > count2)
                return true;
            else
                return index1 > index2;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        
        for(int i = 0; i < mat.size(); ++i)
        {
            int count = 0;
            
            // Use binary search
            
            int lo = 0;
            int hi = mat[i].size();
            
            while(hi > lo)
            {
                int mid = (lo) + (hi-lo)/2;
                
                if(mat[i][mid]==1)
                {
                    lo = mid+1;
                }
                else
                {
                    hi = mid;
                }
            }
            count = lo;
            
            // for(const auto & num: row)
            // {
            //     count += num;
            // }
            
            pq.push({count, i});
        }
        
        vector<int> resultIndices;
        for(int counter = 0; counter < k; ++counter)
        {
            pair<int, int> minElement = pq.top();
            resultIndices.push_back(minElement.second);
            pq.pop();
        }
        
        return resultIndices;
        
    }
};
