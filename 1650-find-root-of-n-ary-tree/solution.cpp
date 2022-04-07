/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) 
    {
        Node* root = nullptr;
        int rootVal = 0;
        for(int i = 0; i < tree.size();i++)
        {
            if(i == 0)
            {
                rootVal = tree[i]->val;
            }
            else
            {
                rootVal ^= tree[i]->val;

            }
            for(int j = 0; j < tree[i]->children.size();j++)
            {
                
                rootVal ^= tree[i]->children[j]->val;
                
            }
        }
        
        
        for(int i = 0; i < tree.size(); i++)
        {
            if(tree[i]->val == rootVal)
            {
                root = tree[i];
                return root;
            }
            
        }
        return root;
        
        
//         unordered_map<Node*, bool> visited;
        
//         for(int i = 0;i < tree.size();i++)
//         {
//             visited[tree[i]] =  false;
//         }
        
//         for(int i = 0; i < tree.size();i++)
//         {
//             for(int j = 0; j < tree[i]->children.size();j++)
//             {
//                 visited[tree[i]->children[j]] = true;
//             }
//         }
        
//         Node* root = nullptr;
//         for(auto itr= visited.begin();itr != visited.end();itr++)
//         {
//             if(itr->second == false)
//             {
//                 root = itr->first;
//                 return root;
//             }
//         }
//         return root;
    }
};
