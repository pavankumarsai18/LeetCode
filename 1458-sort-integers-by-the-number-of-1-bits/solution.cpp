class Solution {
private:
    static int num_bits(int x)
    {
        int num_1 = 0;
        while(x != 0)
        {
            int a = x&1;
            if(a == 1)
            {
                num_1++;
            }
            x >>= 1;
        }
        return num_1;
    }
    
    static bool compare(const int& a, const int& b)  
    {
        int a1 = num_bits(a);
        int a2 = num_bits(b);
        if(a1 == a2)
            return a < b;
        return a1 < a2;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        
        sort(arr.begin(), arr.end(), compare);
        return arr;
        
    }
};
