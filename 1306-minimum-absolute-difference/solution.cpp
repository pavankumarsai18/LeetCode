class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) 
    {
        //sort the array
        //vector<int> duplicate = arr;
        
        sort(arr.begin(), arr.end());
        
        int min_difference = 0;
        //calcuate the difference between each consecutive numbers
        for(int i = 0 ; i < arr.size() - 1; i++)
        {
            if(i == 0)
                min_difference = arr[1] - arr[0];
            else
                if(min_difference > arr[i+1] - arr[i])
                    min_difference = arr[i+1] - arr[i];
        }
        
        vector<vector<int>> result;
        
        for(int i = 0 ; i < arr.size() - 1; i++)
        {
            if(min_difference == arr[i+1] - arr[i])
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[i+1]);
                
                result.push_back(temp);
            }
        }
        //arr = duplicate;
        return result;
    }
};
