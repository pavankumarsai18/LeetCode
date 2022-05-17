/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
        {
            return "null";
        }
        string result = to_string(root->val);
        result += ",[" + serialize(root->left) + "]";
        result += ",[" + serialize(root->right) + "]";
        
        return result;
    }

    string decodeTree(string & data, int & i)
    {
        string result = "";
        stack<char> Stack;
        Stack.push(data[i++]);
        
        while(i < data.size() && Stack.size())
        {
            if(data[i] == '[')
                Stack.push(data[i]);
            else if(data[i] == ']')
                Stack.pop();
            
            if(Stack.size() != 0)
            {
                result += data[i];
            }
            i++;
        }
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        TreeNode* root = nullptr;
        if(data == "null")
            return root;
        
        string rootVal = "";
        int i = 0;
        
        while(i < data.size() && data[i] != ',')
        {
            rootVal += data[i++];
        }

        root = new TreeNode(stoi(rootVal));
        
        i++;
        string leftTree = decodeTree(data, i);
        root->left = deserialize(leftTree);
        
        i++;
        string rightTree = decodeTree(data, i);
        root->right = deserialize(rightTree);
        
        return root;
   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
