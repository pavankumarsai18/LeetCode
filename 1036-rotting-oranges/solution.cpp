class Solution {
private:
    int infect(vector<vector<int>> & G, vector<int>& Count)
    {
        auto prev = Count;
        unordered_set<string> S;
        for(int i = 0; i < G.size(); i++)
        {
            for(int j = 0; j < G[i].size(); j++)
            {
                // if G[i, j] is rotting then we check 4 directionally
                // and rot any that have are fresh
                if(G[i][j] == 2)
                {
                    if(i - 1 >= 0 && G[i - 1][j] == 1)
                    {
                        string s = "";
                        s += to_string(i - 1);
                        s += " ";
                        s += to_string(j);
                        S.insert(s);
                        
                    }
                    if(i + 1 < G.size() && G[i + 1][j] == 1)
                    {
                        string s = "";
                        s += to_string(i + 1);
                        s += " ";
                        s += to_string(j);
                        S.insert(s);

                    }
                    if(j - 1 >= 0 && G[i][j - 1] == 1)
                    {
                        string s = "";
                        s += to_string(i);
                        s += " ";
                        s += to_string(j - 1);
                        S.insert(s);
                    }
                    if(j + 1 < G[i].size() && G[i][j + 1] == 1)
                    {
                        string s = "";
                        s += to_string(i);
                        s += " ";
                        s += to_string(j + 1);
                        S.insert(s);
                        
                    }
                }
            }
            
        }
        
        for(auto itr = S.begin(); itr != S.end(); itr++)
        {
            auto s = *itr;
            string s1 = "";
            string s2 = "";
            bool space_encountered = false;
            for(char c: s)
            {
                if(c == ' ' && space_encountered == false)
                {
                    space_encountered = true;
                }
                
                if(space_encountered)
                {
                    s2 += c;
                }
                else
                {
                    s1 += c;
                }
            }
            
            int i = stoi(s1);
            int j = stoi(s2);
            
            G[i][j] = 2;
            Count[0]--;
            Count[1]++;
        }
        

        if(Count[0] == 0)
            return 1;
        else if(prev[0] == Count[0] && prev[1] == Count[1])
            return -1;
        return 0;
            
            
        
        
    }
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        int minutes = 0;
        
        // 0 --> empty
        // 1 --> fresh
        // 2 --> rotten
        
        // 1 adj(2) = 2  in 1 min
        
        // we run a loop 
        // if the grid still has some fresh oranges and it is exactly same before we ran the loop
        // then we return -1
        // else we continue and as 1 to the number of minutes
        
        
        // Count the number of 1's and 2's
        vector<int> Count = {0,0};

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1) 
                {
                    Count[0]++;
                }
                else if(grid[i][j] == 2)
                {
                    Count[1]++;   
                }
            }
        }
        if(Count[0] == 0)
            return 0;
        else if(Count[0] != 0 && Count[1] == 0)
            return -1;
        
        auto prev = Count;
        do
        {
            prev = Count;
            int ans = infect(grid, Count);
            minutes++;
            if(ans == -1)
                return -1;
            if(ans == 1)
                return minutes;
        }while(prev[0] != Count[0]);
        
        return minutes;
    }
};
