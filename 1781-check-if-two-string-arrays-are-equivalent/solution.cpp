class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string A, B;
        A = B = "";
        
        for(auto & word: word1)
            A += word;
        for(auto & word: word2)
            B += word;
        
        return A == B;
        
    }
};
