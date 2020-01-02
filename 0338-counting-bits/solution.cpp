class Solution {
private:
    int increment(vector<int> & arr)
    {
        int carry = 1;
        for(int i =  0; i < arr.size(); i++)
        {
            if(arr[i] == 0)
            {
                if(carry == 1)
                {
                    arr[i] = 1;
                    break;
                }
            }
            else if(arr[i] == 1)
            {
                if(carry == 1)
                {
                    arr[i] = 0;
                    carry = 1;
                }
            }
        }
        
        int num_ones = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 1)
                num_ones++;
        }
        return num_ones;
    }
public:
    vector<int> countBits(int num) 
    {
        vector<int> arr;
        for(int i = 0; i < 32; i++)
        {
            arr.push_back(0);
        }
        
        vector<int> result;
        result.push_back(0);
        for(int i = 1; i <= num; i++)
        {
            result.push_back(increment(arr));
        }
        return result;
    }
};
