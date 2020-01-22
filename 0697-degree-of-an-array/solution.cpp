class Solution {
public:
    int findShortestSubArray(vector<int>& nums) 
    {
        unordered_map<int, vector<int>> M;
        int max_count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            auto itr = M.find(nums[i]);
            if(itr == M.end())
            {
                vector<int> temp = vector<int>(3);
                temp[0] = i;
                temp[1] = i;
                temp[2] = 1;
                M[nums[i]] = temp;
                if(max_count < M[nums[i]][2])
                    max_count = M[nums[i]][2];
            }
            else
            {
                M[nums[i]][1] = i;
                M[nums[i]][2]++;
                
                if(max_count < M[nums[i]][2])
                    max_count = M[nums[i]][2];
            }
        }
        
        int min_length = nums.size();
        for(auto itr = M.begin(); itr != M.end(); itr++)
        {
            if(itr->second[2] == max_count)
            {
                int len = itr->second[1] - itr->second[0] + 1;
                if(len < min_length)
                    min_length = len;
            }
        }
        
        return min_length;
    }
};
