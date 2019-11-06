class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> A;
        set<int> B;
        for(int i = 0; i < nums1.size(); i++)
        {
            A.insert(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++)
        {
            B.insert(nums2[i]);
        }
        
        vector<int> result;
        for(auto itr = A.begin(); itr != A.end(); itr++)
        {
            auto itr_ = B.find(*itr);
            if(itr_ != B.end())
                result.push_back(*itr);
        }
        return result;
        
    }
};
