class Solution {
public:
    // struct P
    // {
    //     int count;
    //     int index;
    // };
    // bool compare(pair<const int,P> x, pair<int,P> y)
    // {
    //     return x.second.index < y.second.index;
    // }
    
    int findLHS(vector<int>& nums) 
    {
        
        
        map<int, int>num_count;
        map<int, int> first_occurance;
        map<int,int>  last_occurance;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = num_count.find(nums[i]);
            if(itr == num_count.end())
            {
                num_count[nums[i]] = 1;
                first_occurance[nums[i]] = i;
                last_occurance[nums[i]] = i;
            }
            else
            {
                num_count[nums[i]]+= 1;
                last_occurance[nums[i]] = i;
            }
        }
        
        int max_length = 0;
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            int x = itr->second;
            auto itr_ = num_count.find(itr->first + 1);
            
            if(itr_ == num_count.end())
                continue;
            int y =  itr_->second;
            
            
            if(first_occurance[itr_->first]  < last_occurance[itr->first] || first_occurance[itr->first]  < last_occurance[itr_->first] )
            {
                if(max_length < x + y)
                    max_length = x + y;
            }
        }

        
        return max_length;
        
        
        
    }
   
};
