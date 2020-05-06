/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) 
    {
        
        TreeNode* root = new TreeNode();
        
        TreeNode* curNode = root;
        
        bool leftCompleted = false;
 
        
        vector<TreeNode*> Nodes;

        
        int i = 0;
        string val = "";
        
        // Create the root node
        while(i< S.size() && S[i] != '-')
        {
            val += S[i];
            i++;
        }
        //store the value of the root as recorded in the string
        root->val = stoi(val);
        
        // push that back
        Nodes.push_back(root);
        
        // variable to store wheter have visited the left sub tree
        // turns false if we encounter the left sub tree
        bool leftVisited = true;
        
        // iterate in the string s
        while(i < S.size())
        {
            // variable that holds the depth
            int depth = 0;
            while(i < S.size()&&S[i] == '-')
            {
                depth++;
                i++;
            }
            
            // varaible that holds the value 
            string val = "";
            while(i < S.size() && S[i] != '-')
            {
                val += S[i];
                i++;
            }
            
            // Create a nrew Node and make sure that it has the same value as calucated previoulsy
            TreeNode* N = new TreeNode();
            N->val = stoi(val);
            
            
//             cout<<"Pre\n";
//             for(auto n: Nodes)
//             {
//                 cout<<n->val<<" ";
//             }
//             cout<<endl;
            
            
            // if the depth is one and we are in the left sub node
            // then we have visited it so we turn leftvisited to false
            if(depth == 1 && leftVisited)
            {
                leftVisited = false;
            }
            // if we encountered a depth of one after finishing the left sub tree
            // then we change the variable "leftCompleted" to true
            else if(depth == 1)
            {
                leftCompleted = true;
            }
            
            // change the node according to the depth
            curNode = Nodes[depth - 1];
            
            // if the left sub tree has been completed then 
            // we 
            // either modify the node at that depth to reflect the fact that
            // we are in the right sub tree
            // or we push that node back in NOdes
            if(leftCompleted == true)
            {
                if(depth < Nodes.size())
                    Nodes[depth] = N;

                else if(depth >= Nodes.size())
                    Nodes.push_back(N);
            }
            
            // if the left node is not yet competed then we fill out that one
            if(curNode->left == nullptr)
            {
                curNode->left = N;
            }
            // else we fill the right node
            else
            {
                curNode->right = N;
            }
            
            // change current node to N
            curNode = N;
            
            // if Nodes.size is less than depth we add that
            if(Nodes.size() <= depth)
            {
                Nodes.push_back(curNode);
            }
            // if(Nodes[depth-1]->right != nullptr)
            // {
            //     Nodes[depth] = Nodes[depth-1]->right;
            // }
            Nodes[depth] = N;
            
            // cout<<"After\n";
            // for(auto n: Nodes)
            // {
            //     cout<<n->val<<" ";
            // }
            // cout<<endl;

        }
        
        
        return root;
        
            
    }
};
