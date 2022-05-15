class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int startR, startC, endR, endC;
        
        startR = startC = 0;
        endR = matrix.size()-1; endC = matrix[0].size()-1;
        
        
        vector<int> result;
        
        while(startR <= endR && startC <= endC)
        {
            
            int r, c;

            // right
            // cout<<"right"<<endl;
            for(r = startR, c = startC; c <= endC; c++)
            {
                // cout<<"("<<r<<","<<c<<") ";
                result.push_back(matrix[r][c]);
            }
            // cout<<endl;
            
            // down
            // cout<<"down"<<endl;
            for(r = startR + 1, c = endC; r <= endR; r++)
            {
                // cout<<"("<<r<<","<<c<<") ";
                result.push_back(matrix[r][c]);
            }
            // cout<<endl;
            
            // left
            // cout<<"left"<<endl;
            for(r = endR, c = endC-1; c >= startC && startR != endR; c--)
            {
                // cout<<"("<<r<<","<<c<<") ";
                result.push_back(matrix[r][c]);
            }
            // cout<<endl;

            // up
            // cout<<"up"<<endl;
            for(r = endR-1, c = startC; r >= startR+1 && startC != endC; r--)
            {
                // cout<<"("<<r<<","<<c<<") ";
                result.push_back(matrix[r][c]);
            }
            // cout<<endl;

            startR++;
            startC++;
            
            endR--;
            endC--;
            
            // cout<<"rows "<<startR<<" "<<endR<<endl;
            // cout<<"cols "<<startC<<" "<<endC<<endl;
        }
        
        return result;
        
    }
};
