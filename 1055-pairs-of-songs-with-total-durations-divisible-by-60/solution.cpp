class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) 
    {
        unordered_map<int, vector<int>> n_ind;
        
        int max = 0;
        for(int i = 0; i < time.size(); i++)
        {
            if(max < time[i])
                max = time[i];
            
            auto itr = n_ind.find(time[i]);
            
            if(itr == n_ind.end())
            {
                vector<int> temp;
                temp.push_back(i);
                n_ind[time[i]] = temp;
            }
            else
            {
                n_ind[time[i]].push_back(i);
            }
        }
        int result = 0;
        for(int i = 0; i < time.size(); i++)
        {
            int M = 0;
            while(M <= 2*(max + max%60))
            {
                auto itr = n_ind.find(M - time[i]);
                
                if(itr != n_ind.end())
                {
                    for(int j = 0; j < itr->second.size(); j++)
                    {
                        if(itr->second[j] > i)
                            result ++;
                    }
                }
                
                M += 60;  
            }
        }
        return result;
    }
};
