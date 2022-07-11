class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) 
    {
        const int n = nums.size();
        int left, sum;        
        double avg, maxAvg, K;
        avg = maxAvg = 0.0;
        K = k*1.0;
        left = sum = 0;

        for(int right = 0; right < n;)
        {
            if(right != 0)
            {
                sum += (nums[right++] - nums[left++]);
                avg = sum/K;
                if(avg > maxAvg) maxAvg = avg;
            }
            else
            {
                while(right < n && right < k){sum += nums[right++];}
                avg = maxAvg = sum/K;
            }
        }
        
        return maxAvg;
        
    }
};
