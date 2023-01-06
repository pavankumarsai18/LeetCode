class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());

        long long total = coins;
        int ans = 0;

        while(!pq.empty() && total >= pq.top())
        {
            total -= pq.top();
            pq.pop();
            ans++;
        }

        return ans;
        
    }
};
