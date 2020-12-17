class Solution {
private:
    void printArr(vector<int>& nums)
    {
        for(auto & n: nums)
        {
            cout<<n<<" ";
        }
    }
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int indexA = m - 1;
        int indexB = n - 1;
        
        int index = nums1.size() - 1;
        
        while(indexA >= 0 && indexB >= 0)
        {
            // cout<<"index "<<index<<endl;
            // cout<<"indexA "<<indexA<<endl;
            // cout<<"indexB "<<indexB<<endl;
            
            if(nums1[indexA] > nums2[indexB])
            {
                nums1[index] = nums1[indexA];
                index--;
                indexA--;
            }
            else
            {
                nums1[index] = nums2[indexB];
                index--;
                indexB--;
            }
            // printArr(nums1);
            // cout<<endl;
        }
        
        while(indexB >= 0)
        {
            nums1[index] = nums2[indexB];
            index--;
            indexB--;
        }
        
        
    }
};
