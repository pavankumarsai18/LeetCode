class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
        
        while(left + 1 < arr.size() && arr[left] < arr[left + 1])
        {
            left++;
        }
        if(left == arr.size())
            return false;
        while(right > 0 && arr[right - 1] > arr[right])
        {
            right--;
        }
        if(right == 0)
            return false;
        
        if(left < arr.size() - 1 && right > 0 && right == left)
            return true;
        return false;
        
    }
};
