class Solution {
private:
    int complement(int x)
    {
        if(x == 1)
            return 1;
        if(x == 2 )
            return 3;
        if(x == 3)
            return 2;
        
        int n = floor(log2(x));
        int comp = ( int(pow(2, n))*3 ) - 1 - x;
        return comp;
    }
public:
    vector<int> pathInZigZagTree(int label) 
    {
        vector<int> path;
        path.push_back(label);
        
        int num = label;
        while(num != 1)
        {
            num /= 2;
            num = complement(num);
            path.push_back(num);
        }
        
        for(int i = 0; i < path.size()/2; i++)
        {
            swap(path[i], path[path.size() - i - 1]);
        }
        
        return path;
    }
};
