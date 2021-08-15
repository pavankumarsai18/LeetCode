class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int v1, v2, v3, v4;
        
        v1 = edges[0][0];
        v2 = edges[0][1];
        v3 = edges[1][0];
        v4 = edges[1][1];
        
        if(v1 == v3 || v1 == v4)
            return v1;
        if(v2 ==  v3 || v2 == v4)
            return v2;
        
        return v3;
    }
};
