class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        unordered_set<int> s;
        int numZero = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            s.insert(arr[i]);
            if(arr[i] == 0)
                numZero++;
        }
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i] == 0 && numZero > 1)
            {
                return true;
            }
            else if(arr[i] != 0){
                int val = arr[i]*2;

                auto itr = s.find(val);

                if(itr != s.end())
                {
                    // cout<<val<<" "<<arr[i]<<endl;
                    return true;
                }
            }
        }
        return false;
    }
};
