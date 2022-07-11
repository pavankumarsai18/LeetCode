class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) 
    {
        int count, avg,sum, left; 
        count = avg = sum = left = 0;
        
        for(int right = 0; right< arr.size();)
        {
            if(right != 0)
            {
                sum += (arr[right++] - arr[left++]); 
            }  
            else
            {
                while(right < k){sum += arr[right++];}
            }
            
            avg = sum/k;
            if(avg >= threshold) count++; 
        }
        
        return count;
    }
};
