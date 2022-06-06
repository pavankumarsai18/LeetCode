class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) 
    {
        const int n = mat.size();
        
        
        int topR, botR, topC, botC;
        topR = topC = botC = 0;
        botR = n - 1;
        
        int diagSum = 0;
        
        while(topR < n && topC < n)
        {
            diagSum += (mat[topR][topC] + mat[botR][botC]);
            
            if(topR == botR && topC == botC)
                diagSum -= mat[botR][botC];

            topR++;
            topC++;
            
            botR--;
            botC++;
        }
        
        return diagSum;
    }
};
