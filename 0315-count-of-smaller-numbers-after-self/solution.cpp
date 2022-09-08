class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        const int n = nums.size();
        
        vector<int> result(n);
        vector<int> indices(n);
        
        for(int i = 0; i < n; i++)
        {
            indices[i] = i;
        }
        
        mergeSort(indices, 0, n, result, nums);
        
        
        return result;
    }
    
    void mergeSort(vector<int> & indices, int left, int right, vector<int> & result, vector<int> & nums)
    {
        if(right - left <= 1) return;
        
        int mid = (left + right)/2;
        
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        
        merge(indices, left, right, mid, result, nums);
    }
    
    void merge(vector<int> & indices, int left, int right, int mid, vector<int>& result, vector<int>& nums)
    {
        
        int i = left;
        int j = mid;
        
        vector<int> temp;
        
        while(i < mid && j < right)
        {
            if(nums[indices[i]] <= nums[indices[j]])
            {
                result[indices[i]] += (j - mid);
                temp.push_back(indices[i]);
                i++;
            }
            else
            {
                temp.push_back(indices[j]);
                j++;
            }
        }
        
        while(i < mid)
        {
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        
        while(j < right)
        {
            temp.push_back(indices[j]);
            j++;
        }
        
        move(temp.begin(), temp.end(), indices.begin() + left);
        
        
        
    }
};
