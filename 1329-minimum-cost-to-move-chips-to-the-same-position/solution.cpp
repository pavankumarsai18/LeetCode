class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) 
    {
        
        //1. need to move the minimum number of chips to left or right
        //2. need to maximize the shift that are even
        
        // count all items at odd place
        // count all items at even place

        //can bring all the odd chips to one place 
        //can bring all the even chips to one place
        //then find the minimum number between them and return that as a result
        
        
        unordered_map<int, int> pos_count;
        for(int i = 0; i < chips.size(); i++)
        {
           auto itr = pos_count.find(chips[i]);
            if(itr == pos_count.end())
                pos_count[chips[i]] = 1;
            else
                pos_count[chips[i]]++;
        }
        int even = 0;
        int odd = 0;
        for(auto itr = pos_count.begin(); itr != pos_count.end(); itr++)
        {
            if(itr->first%2 == 0)
                even += itr->second;
            else
                odd += itr->second;
        }
        // 1-->1
        // 2-->1
        // 3 -->1
        
        if(odd < even)
            return odd;
        else
            return even;
        
    }
};
