class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> S;
        while(n != 1)
        {
            auto itr = S.find(n);
            if(itr == S.end())
                S.insert(n);
            else
                return false;
            int temp = n;
            int res = 0;
            while(temp != 0)
            {
                int digit = temp%10;
                res += digit*digit;
                temp /= 10;
            }
            n = res;
        }
        return true;
        
    }
};
