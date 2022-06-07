class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int ind2, ind1;
        ind2 = n - 1;
        ind1 = m - 1;
        
        int total = n + m;
        for(int i = 0; i < total && ind1 >= 0 || ind2 >= 0; i++)
        {
            // cout<<"i "<<i<<" ind1 "<<ind1<<" ind2 "<<ind2<<endl;
            if(ind1 >= 0 && ind2 < 0)
            {
                nums1[total-i-1] = nums1[ind1--];
            }
            else if(ind1 < 0 && ind2 >= 0)
            {
                nums1[total-i-1] = nums2[ind2--];
            }
            else
            {
                if(nums2[ind2] > nums1[ind1])
                {
                    nums1[total - i - 1] = nums2[ind2--];
                }
                else
                {
                    nums1[total - i - 1] = nums1[ind1--];
                }
            }
        }
        
        return;
        
    }
};
