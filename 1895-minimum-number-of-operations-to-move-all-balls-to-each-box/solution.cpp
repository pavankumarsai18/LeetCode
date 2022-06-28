class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        const int size = boxes.size();
        
        int numOnesVisited,numOnes, prefix;
        numOnesVisited = numOnes = prefix = 0;
        
        for(int i = 0; i < size; i++)
        {
            if(boxes[i] == '1')
            {
                numOnes++;
                prefix += i;
            }
        }
        
        vector<int> ans(boxes.size(),0);
        
        for(int i = 0; i < size; i++)
        {
            ans[i] = prefix;
            if(boxes[i] == '1')
            {
                numOnesVisited++;
                numOnes--;
            }
            
            prefix += numOnesVisited;
            prefix -= numOnes;
        }
        
        return ans;
    }
};
