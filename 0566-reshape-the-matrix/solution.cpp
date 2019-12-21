class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        
        
        if(r*c != nums.size()*nums[0].size())
            return nums;
        
        vector<vector<int>> result;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < nums[0].size(); j++)
            {
                
                if( (count)%c == 0)
                {
                    vector<int>temp;
                    temp.push_back(nums[i][j]);
                    result.push_back(temp);
                }
                else
                {
                    
                    result[result.size() - 1].push_back(nums[i][j]);
                }
                
                count++;
            }
            
        }
        
        return result;
        
    }
};
