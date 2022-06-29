class Solution {
public:

    bool verifyPreorder(vector<int>& preorder) 
    {
       int threshold = INT_MIN;
       int treeStack = -1;
        
        for(int i = 0; i < preorder.size(); i++)
        {
            int num = preorder[i];
            if(num < threshold) return false;
            
            while(treeStack != -1 && num > preorder[treeStack])
            {
                threshold = preorder[treeStack];
                treeStack--;
            }
            preorder[++treeStack] = preorder[i];
           
        }
        return true;
    }
};
