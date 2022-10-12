class Solution {
public:
    bool validTriangle(int & a, int & b, int & c)
    {
        return ((a+b) > c && (b+c) > a && (c+a) > b);
    }
    
    int largestPerimeter(vector<int>& nums)
    {
        if(nums.size() < 3) return 0;
        
        priority_queue<int> pq;
        for(int & num: nums)
        {
            pq.push(num);
        }
        
        bool foundTriangle = false;
        deque<int> sides;
        int ans = 0;
        
        while(sides.size() < 3)
        {
            sides.push_back(pq.top());
            pq.pop();
        }
        
        
        if(validTriangle(sides[0], sides[1], sides[2]))
        {
            ans = sides[0] + sides[1] + sides[2];
            return ans;
        }
        
        while(pq.size()>0)
        {
            sides.pop_front();
            sides.push_back(pq.top()); pq.pop();

            // cout<<sides[0]<<" "<<sides[1]<<" "<<sides[2]<<" "<<ans<<endl;
            if(validTriangle(sides[0], sides[1], sides[2]))
            {
                ans = sides[0] + sides[1] + sides[2];
                return ans;
            }
        }
        
    
        return ans;
        
    }
};
