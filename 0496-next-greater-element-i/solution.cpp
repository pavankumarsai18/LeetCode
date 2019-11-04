class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        
        vector<int> result;
        bool found = false;
        bool encountered = false;
        for(int i = 0; i < nums1.size(); i++)
        {
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                    encountered = true;
                if(nums1[i] < nums2[j] && encountered)
                {
                    found = true;
                    result.push_back(nums2[j]);
                    break;
                }
            }
            if(found == false)
                result.push_back(-1);
            found = false;
            encountered = false;
        }
        return result;
//         map<int, int> el_index;
        
//         vector<int> temp  = nums2;
//         sort(temp.begin(), temp.end());
        
//         for(int i = 0; i < nums2.size(); i++)
//         {
//             el_index[temp[i]] = i;
//         }
        
//         //1 --> 0, 2 --> 1, 3--> 2, 4 --> 3
        
//         vector<int> result;
//         for(int i = 0; i < nums1.size(); i++)
//         {
//             //cout<<nums1[i]<<" : "<<el_index[nums1[i]] + 1<<endl;
//             if(el_index[nums1[i]] + 1 < nums2.size())
//                 result.push_back(temp[el_index[nums1[i]] + 1]);
//             else
//                 result.push_back(-1);
//         }
        
        return result;
    }
};
