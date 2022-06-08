class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums1.size() > nums2.size())
            return intersect(nums2, nums1);        
        
        unordered_map<int, int> num1Map;
        
        for(int i = 0; i < nums1.size(); i++)
            num1Map[nums1[i]]++;
        
        vector<int> result;        
        for(auto n: nums2)
        {
            if(num1Map.find(n) != num1Map.end() && num1Map[n] >= 1)
            {
                result.push_back(n);
                num1Map[n]--;
            }
        }
        
        return result;
        
    }
};
