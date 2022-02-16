class Solution {
public:
    int countPoints(string rings) 
    {
        vector<vector<int>> rods;
        
        for(int i = 0; i < 10; i++)
        {
            vector<int> colors = {0,0,0};
            rods.push_back(colors);
        }
        
        
        for(auto i = 0; i < rings.size(); i++)
        {
            if(rings[i] == 'R')
            {
                rods[rings[i+1] -48][0] += 1;
                i++;
            }
            else if(rings[i] == 'G')
            {
                rods[rings[i+1] -48][1] += 1;
                i++;
            }
            else if(rings[i] == 'B')
            {
                rods[rings[i+1] -48][2] += 1;
                i++;

            }
        }
        
        int result = 0;
        for(int i = 0; i < rods.size(); i++)
        {
            if(rods[i][0] && rods[i][1] && rods[i][2])
                result += 1;
        }
       
        return result;
        
        
        
        
        
    }
};
