class Vector2D {
private:
    int r, c, n;
    vector<vector<int>>* vec;
public:
    Vector2D(vector<vector<int>>& vec) 
    {
        this->vec = &vec;
        r = c = 0;
        n = vec.size();
    }
    
    int next() 
    {
        while(r < n && (*vec)[r].size() == 0)
            r++;
        
        int result =  (*vec)[r][c++];
        if(r < n && c >= (*vec)[r].size())
        {
            r++;
            c = 0;
        }
        return result;
        
    }
    
    bool hasNext() 
    {
        while(r < n && (*vec)[r].size() == 0)
            r++;
        
        if(r < n - 1 || (r == n-1 && c < (*vec)[r].size()))
            return true;

        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
