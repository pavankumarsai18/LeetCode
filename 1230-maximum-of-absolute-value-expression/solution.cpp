class Solution {
public:
    int maxAbsVal(vector<int> & arr1, vector<int>& arr2, int sign1, int sign2)
    {
        int maxans = 0;
        const int n = arr1.size();
        int max1, min1;
        max1 = INT_MIN;
        min1 = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            
            int val = arr1[i] + sign1*arr2[i] + sign2*i;
            max1    = max(max1, val);
            min1    = min(min1, val);
        }
        maxans = max(maxans, abs(max1-min1));
        return maxans;
        
    }
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int maxans = 0;        

        maxans = max(maxans, maxAbsVal(arr1, arr2,1, 1));
        maxans = max(maxans, maxAbsVal(arr1, arr2,1, -1));
        maxans = max(maxans, maxAbsVal(arr1, arr2,-1, 1));
        maxans = max(maxans, maxAbsVal(arr1, arr2,-1, -1));

        return maxans;
    }
};
