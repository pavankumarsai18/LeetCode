class Solution {
public:
    int kthFactor(int n, int k) 
    {

        vector<int> lo;
        vector<int> hi;
        for(int i = 1; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                // cout<<"added "<<i<<" "<<n/i<<endl;
                lo.push_back(i);
                if(i*i != n)
                    hi.push_back(n/i);
            }
        }
        // cout<<k<<" "<<lo.size()<<" "<<hi.size()<<endl;
        
        if(k <= lo.size())
        {
            return lo[k-1];
        }
        else if(hi.size() + lo.size() >= k)
        {
            // lo.size()
            // hi.size() - k + lo.size()
            int newIndex = (k - lo.size()) - 1;
            newIndex = hi.size() - 1 - newIndex;
            // cout<<newIndex<<endl;
            return hi[newIndex];
        }
        return -1;
        
    }
};
