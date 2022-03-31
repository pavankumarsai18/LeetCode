class StringIterator {
private:
    string compressedString;
    int index;
    int count;
    char curChar;
public:
    StringIterator(string compressedString) 
    {
        this->compressedString = compressedString;
        this->index = 0;
        this->count = 0;
        this->curChar = ' ';
        
        
    }
    
    char next() {
        
        if(this->curChar == ' ' || count == 0)
        {
            if(index >= compressedString.length())
            {
                curChar = ' ';
                count = 0;
                return curChar;
            }
            
            while(this->index < this->compressedString.length())
            {
                if(isalpha(compressedString[index]))
                {
                    curChar = compressedString[index];
                    index++;
                }
                
                string number = "";
                while(index < compressedString.length() && isdigit(compressedString[index]))
                {
                    number += compressedString[index];
                    index++;
                }
                
                count = stoi(number);
                break;
            }
            count--;
            return curChar;
        }

        count--;
        return curChar;
        
    }
    
    bool hasNext() 
    {
        
        if(index >= compressedString.length() && count <= 0)
            return false;
        return true;
        
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
