class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) 
    {
        if(deck.size() == 0)
            return false;
        unordered_map<int, int> num_count;
        
        for(int i = 0; i < deck.size(); i++)
        {
            auto itr = num_count.find(deck[i]);
            if(itr == num_count.end())
            {
                num_count[deck[i]] = 1;
            }
            else
            {
                num_count[deck[i]] += 1;
            }
        }
        
        
        for(int i = 2; i <= deck.size(); i++)
        {
            bool p = true;
            for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
            {
                if(itr->second % i != 0)
                {
                    p = false;
                }
            }
            if(p == true)
                return true;
        }
        return false;
        
    }
};
