class Solution {
private:
    bool Bijection(string& A, string& B)
    {
        if(A.size() != B.size())
            return false;
        
        bool result = false;
        
        unordered_map<char, char> forward;
        unordered_map<char, char> backward;
        
        // A[i] -> B[i] // forward
        // A[i] <- B[i] // backward
        
        for(int i = 0; i < A.size(); i++)
        {
            auto itr1 = forward.find(A[i]);
            auto itr2 = backward.find(B[i]);
            
            if(itr1 == forward.end())
            {
                forward[A[i]] = B[i];
            }
            else
            {
                if(forward[A[i]] != B[i])
                    return false;
            }
            
            if(itr2 == backward.end())
            {
                backward[B[i]] = A[i];
            }
            else
            {
                if(backward[B[i]] != A[i])
                    return false;
            }
        }
    
        
        return true;
    
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> result;
        
        for(auto word: words)
        {
            if(Bijection(word, pattern))
                result.push_back(word);
        }
        
        return result;
    }
};
