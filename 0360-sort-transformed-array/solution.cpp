class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        
        vector<int> ans;

        if(a == 0)
        {
            for(int num: nums)
            {
                ans.push_back(b*num + c);
            }
            if(b < 0)
            {
                reverse(ans.begin(), ans.end());
            }
            return ans;
        }
        // ax^2 + bx + c
        // x = -b/2a
        
        
        // y(x`) = y(x``)
        
        // x = -b/2a - dx
        // dx = (-b/2a - x)
        // -b/a -x
        // exp search for -b/2a
        // lhs we convert it into -b/2a - dx
        // for each element in new x we compute y = ax^2 _ bx + c and append to result
        
        
        double mid_point = -(1.0*b)/(2.0 * a);
        const int n = nums.size();
        int splitLength = 0;
        vector<int> newNums(n, 0);
        
        // find splitlength
        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= mid_point)
            {
                splitLength++;
            }
            else
                break;
        }
        
        // create new points
        for(int i = 0; i < splitLength; i++)
        {
            if(nums[i] <= mid_point)
            {
                newNums[splitLength - i-1] = nums[i];
            }
            else
            {
                break;
            }
        }
        
    
        int index1   = splitLength - 1;
        int index2   = n - 1;
        int curIndex = n - 1;
        
        // Merge
        while(index2 >= 0 && index1 >= 0)
        {            
            if((2*(mid_point) - newNums[index1]) >= nums[index2])
            {
                newNums[curIndex--] = newNums[index1--];
            }
            else
            {
                newNums[curIndex--] = nums[index2--];
            }
        }
        
        while(curIndex >= 0 && index1 >= 0)
        {
            newNums[curIndex--] = newNums[index1--];
        }
        while(curIndex >= 0 && index2 >= 0)
        {
            newNums[curIndex--] = nums[index2--];
        }
    
        
        // calcuate the value
        for(int x: newNums)
        {
            ans.push_back(a*x*x + b*x + c);
        }
        
        // reverse if the parabola opens downwards
        if(a < 0)
        {
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
            
    }
};
