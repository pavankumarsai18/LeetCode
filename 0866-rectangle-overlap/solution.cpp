class Solution {
private:
    int min(int x,  int y)
    {
        if(x < y)
            return x;
        return y;
    }
    int max(int x, int y)
    {
        if(x > y)
            return x;
        return y;
    }
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) && // width > 0
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));  // height > 0

    }
};
