class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int ind_1 = 0;
        int ind_2 = 0;
        
        int min_len = (m < n)? m : n;
        vector<int> result;
        
        for(int i = 0; i < m + n; i++)
        {
            if(ind_1 < m && ind_2 < n && nums1[ind_1] < nums2[ind_2])
            {
                result.push_back(nums1[ind_1]);
                ind_1++;
            }
            else if(ind_1 < m && ind_2 < n)
            {
                result.push_back(nums2[ind_2]);
                ind_2++;
            }
            else 
            {
                if(ind_1 == m && ind_2 != n)
                {
                    for(int j = ind_2; j < n; j++)
                    {
                        result.push_back(nums2[j]);
                    }
                    i = m + n;
                }
                else if(ind_1 != m && ind_2 == n)
                {
                    for(int j = ind_1; j < m; j++)
                    {
                        result.push_back(nums1[j]);
                    }
                    i = m + n;
                }
            }
        }
        
        nums1 = std::move(result);
    }
};
