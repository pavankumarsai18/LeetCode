class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int index1, index2;
        int ptr1, ptr2;
        
        
        index1 = index2 = ptr1 = ptr2 = 0;
        
        while(index1 < word1.size() && index2 < word2.size())
        {
                   
            if(word1[index1][ptr1++] != word2[index2][ptr2++]) return false;
            
            if(ptr1 == word1[index1].size()){index1++; ptr1 = 0;}
            if(ptr2 == word2[index2].size()){index2++; ptr2 = 0;}
                        
        }
        
        return index1 == word1.size() && index2 == word2.size();
    }
};
