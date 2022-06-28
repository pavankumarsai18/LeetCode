class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int index = 0;
        const int n = arr.size();
        
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int pivot = left + ((right - left)>>1);
            
            if(arr[pivot] - pivot - 1 < k)
            {
                left = pivot + 1;
            }
            else
            {
                right = pivot - 1;
            }
        }
        
        return left + k;
    }
};
