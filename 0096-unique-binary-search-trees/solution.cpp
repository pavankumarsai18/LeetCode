class Solution {
public:
    int numTrees(int n) 
    {
        if(n==0)
            return 1;
        if(n == 1)
            return 1;
        else if(n == 2)
        {
            return 2;
        }
        
        //1 root // 0 left and n-1 right  
        //2 root // 1 left and n-2 right
        //3 root // 2 left and n-3 right
        int possibleTrees[n+1];
        possibleTrees[0] = 1;
        possibleTrees[1] = 1;
        possibleTrees[2] = 2;
        
        for(int numNodes = 3; numNodes <= n; numNodes++)
        {
            int numPossible = 0;
            for(int root = 1; root <= numNodes; root++)
            {
                int numLeft  = possibleTrees[(root-1)];
                // int numRight = possibleTrees[numNodes - (root-1) - 1];
                int numRight = possibleTrees[numNodes - root];

                numPossible += numLeft*numRight;
            }
            possibleTrees[numNodes] = numPossible;
        }
        return possibleTrees[n];
    }
};
