class Trie
{
public:
    vector<Trie*> children;
    char ch;
    bool ends;
    int count;
    Trie(char val='0'): ch(val)
    {
        this->children = vector<Trie*>(26, nullptr);
        this->ends = false;
        count = 0;
    }
    
    void addWord(string & word)
    {
        Trie* cur = this;
        for(int i = 0; i < word.size(); i++)
        {
            int index = word[i] - 'a';
            
            if(cur->children[index] == nullptr)
            {
                cur->children[index] = new Trie(word[i]);
            }
            
            cur = cur->children[index];
            if(i == word.size()-1)
            {
                cur->ends = true;
                cur->count++;
            }
        }
    }
    
    
};

class Solution 
{
public:
    int countPrefixes(vector<string>& words, string s) 
    {
        Trie* trie = new Trie();
        
        for(string & word: words)
        {
            trie->addWord(word);
        }
        Trie* cur = trie;

        int ans = 0;
        for(int i = 0; i < s.size(); i++)
        {

            int indx = s[i] - 'a';
            if(cur->children[indx] != nullptr)
            {

                cur = cur->children[indx];
                
                if(cur->ends)
                {                    
                    ans+= cur->count;
                }
            }
            else
            {
                break;
            }
        }
        
        return ans;
    }
};
