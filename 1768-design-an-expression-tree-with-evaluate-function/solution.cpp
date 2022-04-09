/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class treeNode: virtual public Node{
private:
    treeNode* left;
    treeNode* right;
    string val;
public:
    treeNode(treeNode* left=nullptr, treeNode* right=nullptr, const string & val="")
    {
        this->left = left;
        this->right = right;
        this->val = val;
    }
    
    int evaluate() const
    {
        // Node::evaluate();
        
        // Perform post fix traversal and then return the value
        if(left == nullptr && right==nullptr)
        {
            return stoi(val);
        }
        
        int leftVal  = left->evaluate();
        int rightVal = right->evaluate();
        
        if(val == "+")
            return leftVal + rightVal;
        if(val == "-")
            return leftVal - rightVal;
        if(val == "*")
            return leftVal * rightVal;
        return leftVal / rightVal;
    }
    
    void print()
    {
        if(left)
            left->print();
        
        if(right)
            right->print();
        
        cout<<" "<<val<<" ";
    }
};


/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) 
    {
        Node* result = nullptr;
        
        stack<treeNode*> S;
        for(int i = 0; i < postfix.size();i++)
        {
            if(postfix[i] != "+" && postfix[i] != "/"  && postfix[i] != "-" && postfix[i] != "*" )
            {
                treeNode* n = new treeNode(nullptr, nullptr, postfix[i]);
                S.push(n);
            }
            else
            {
                treeNode* operand1 = S.top(); S.pop(); 
                treeNode* operand2 = S.top(); S.pop();
                treeNode* n = new treeNode(operand2, operand1, postfix[i]);
                S.push(n);
            }
        }
        // S.top()->print();
        result = S.top();
        // result->print();
        return result;
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
