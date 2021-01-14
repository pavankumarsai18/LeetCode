class Trie{
 public:
    struct Node{
        bool ended = false;
        vector<Node*> children{vector<Node*>(26, NULL)};
    };
    
    Node* Root;
    Node* cur;
    
    
    void dfsWithPrefix(Node* cur, string & word, vector<string>& result)
    {
        if(result.size() == 3)
            return;
        if(cur->ended)
            result.push_back(word);
        
        for(char c = 'a'; int(c-'z') <= 0; c++)
        {
            if(cur->children[c-'a']){
                word += c;
                dfsWithPrefix(cur->children[c-'a'], word, result);
                word.pop_back();
            }
        }
    }
    Trie(){
        Root = new Node();
    }
    
    void insert(string & s)
    {
        cur = Root;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(cur->children[s[i] - 'a'] == NULL)
                cur->children[s[i] - 'a'] = new Node();
            cur = cur->children[s[i]-'a'];
        }
        
        cur->ended = true;
    }
    
    vector<string> getWordsStartingWith(string & prefix)
    {
        cur = Root;
        vector<string> result;
        
        for(int i = 0; i < prefix.size();i++)
        {
            if(cur->children[prefix[i] - 'a'] == NULL)
                return result;
            cur = cur->children[prefix[i] - 'a'];
        }
        
        dfsWithPrefix(cur, prefix, result);
        return result;
    }
};


class Solution {
public:

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        Trie trie = Trie();
        vector<vector<string>> result;
        
        for(string & s: products){
            trie.insert(s);
        }
        
        string prefix = "";
        
        for(char c: searchWord){
            prefix += c;
            result.push_back(trie.getWordsStartingWith(prefix));
        }
        return result;
    }
    

};
