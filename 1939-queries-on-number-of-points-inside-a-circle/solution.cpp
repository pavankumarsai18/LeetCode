class Solution {
private:
    string stringify(vector<int> & V)
    {
        string result = "[";
        
        for(int i = 0; i < V.size(); i++)
        {
            result += to_string(V[i]);
            
            if(i != V.size() - 1)
            {
                result += ",";
            }
        }
        
        result += "]";
        return result;
    }
    
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)     
    {
        vector<int> result;
        unordered_map<string, bool> M;
        
        for(auto & circle: queries)
        {
            int numPoints = 0;

            for(auto & point: points)
            {
                int inside = ((point[0] - circle[0])*(point[0] - circle[0])) + ((point[1] - circle[1])*(point[1] - circle[1])) - (circle[2]*circle[2]);
                
                if(inside <= 0)
                {
                    numPoints++;
                }
            }
            
            result.push_back(numPoints);
        }
        
        return result;
    }
};
