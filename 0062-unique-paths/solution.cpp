class Solution {
private:
    int uniquePathsCalculate(int m, int n, unordered_map<string, int> & memo)
    {
        string key = "";
        key += std::to_string(m) + ","+std::to_string(n);
        // for(auto & itr : memo)
        // {
        //     cout<<"("<<itr.first<<") -> "<<itr.second<<endl;
        // }
        if(memo.find(key) != memo.end())
        {
            return memo[key];
        }
        if(m == 0 || n == 0)
        {
            memo[key] = 0;
            return 0;
        }
        
        if(m == 1)
        {
            memo[key] = 1;
            return 1;
        }
        else if(n == 1)
        {
            memo[key] = 1;
            return 1;
        }
        
        int result = uniquePathsCalculate(m-1, n, memo) + uniquePathsCalculate(m, n-1,memo);
        // cout<<"result "<<result<<endl;
        memo[key] = result;
        
        return result;
        
    }
public:
    int uniquePaths(int m, int n) 
    {
        unordered_map<string, int> memo;
        return uniquePathsCalculate(m, n, memo);
        
        
    }
};
