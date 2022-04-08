class KthLargest 
{
private:
    priority_queue<int, vector<int>, greater<int>> Q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) 
    {
        this->k = k;

        for(int i = 0; i < nums.size();i++)
        {
            Q.push(nums[i]);
        }
        while(Q.size()>k)
            Q.pop();

    }
    
    int add(int val) 
    {
        Q.push(val);
        if(Q.size() > k)
        {
            Q.pop();
        }
        
        return Q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
