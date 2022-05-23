class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        vector<int> Stack;
        for(int i = 0; i < heights.size(); i++)
        {
            if(Stack.size() == 0)
            {
                Stack.push_back(i);
            }
            else
            {
                while(Stack.size() && heights[Stack[Stack.size()-1]] <= heights[i])
                {
                    Stack.pop_back();
                }
                Stack.push_back(i);
            }
        }
       
        return Stack;
    }
    
};
