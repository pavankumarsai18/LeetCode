class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return vector<int>();
        }
        // find the maximum element
        int max = nums[0];
        
        for(auto &x: nums)
        {
            if(x > max)
                max = x;
        }
        
       // brute force approach
//         vector<int> result;
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(nums[i] == max)
//             {
//                 result.push_back(-1);
//             }
//             else
//             {
//                 for(int j = i+1; j <= nums.size(); j++)
//                 {
//                     if(j < nums.size() && nums[i] < nums[j])
//                     {
//                         result.push_back(nums[j]);
//                         break;
//                     }
//                     else if(j == nums.size())
//                     {
//                         j = -1;
//                     }
//                 }
//             }
//         }
        
//         return result;
        
        
        // better approach
        
        // create a vector<pair<int,int>>
        // the first element is the index and the second int is the index of the other element
        // S --> acts as a stack
        vector<pair<int,int>> S;
       
        vector<int> result = vector<int>(nums.size());
        int not_found = 0;
        int size = 0;
        bool second_run = false;
        
        for(int i = 0; i<= nums.size(); i++)
        {       
            if(size == result.size())
            {   
                break;
            }
            
            if(i == nums.size())
            {
                second_run = true;
                i = -1;
                continue;
            }
            
            for(int j = 0; j < S.size(); j++)
            {
                if(nums[S[j].first] < nums[i] && S[j].second == -1)
                {
                    S[j].second = i;
                    result[S[j].first] = nums[S[j].second];
                    size++;
                    not_found--;
                }
            }
            
            if(not_found == 0)
            {
                S.clear();
            }
            
            if(nums[i] == max && second_run == false)
            {
                result[i] = -1;
                size++;
            }
            
            else if(second_run == false)
            {
                pair<int, int> p;
                p.first = i;
                p.second = -1;
                S.push_back(p);
                not_found ++;
            }
        }
        return result;
        
    }
};
