class Solution {
public:
    int findSpecialInteger(vector<int>& arr) 
    {
        int count = 0;
        
        for(int i = 1; i < arr.size(); i++)
        {
            //cout<<count<<" ";
            if(arr[i - 1] == arr[i])
            {
                if(count == 0)
                    count = 1;
                count++;
                if(count > arr.size()/4)
                    return arr[i];
            }
            else
            {
                count = 0;
            }
        }
        
        return arr[0];
        
    }
};
