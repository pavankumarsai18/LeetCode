class Solution {
public:
    int numRabbits(vector<int>& answers) 
    {
        if(answers.size() == 0)
            return 0;
        
        unordered_map<int, int> num_count;
        for(auto &x: answers)
        {
            auto itr = num_count.find(x);
            if(itr == num_count.end())
                num_count[x] = 0;
            num_count[x]++;
        }
        
        
        int total_rabbits = 0;
        for(auto itr = num_count.begin(); itr != num_count.end(); itr++)
        {
            int y = itr->second;
            int x = itr->first;
            if(x == 0)
            {
                // cout<<x<<" "<<y<<" "<<itr->second<<endl;
                total_rabbits += itr->second;
            }
            else
            {
                if(y > (x + 1))
                {
                    // cout<<x<<" "<<y<<" "<<(y/(x+1))*(x+1) + (x+1)<<endl;
                    int z = y%(x+1);
                    if(z == 0)
                        total_rabbits += (y/(x+1))*(x+1);
                    else
                        total_rabbits += (y/(x+1))*(x+1) + (x+1);
                }
                else
                {
                    // cout<<x<<" "<<y<<" "<<x+1<<endl;
                    total_rabbits += x+1; 
                }
            }
        }
        return total_rabbits;   
    }
};
