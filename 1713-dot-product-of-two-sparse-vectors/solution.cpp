class SparseVector {
private:
    vector<pair<int, int>> N;
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i])
            {
                N.push_back(make_pair(i, nums[i]));
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        
        int index1 = 0;
        int index2 = 0;
        int result = 0;
        while(index1 < N.size() && index2 < vec.N.size())
        {
            if(N[index1].first > vec.N[index2].first)
            {
                index2++;
            }
            else if(N[index1].first < vec.N[index2].first)
            {
                index1++;
            }
            else
            {
                result += N[index1].second*vec.N[index2].second;
                index2++;
                index1++;
            }
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
