class NumArray {
private:
    vector<vector<int>> sum;
    vector<vector<bool>> computed;
    vector<int> nums;
    int num_calls = 0;
public:
    NumArray(vector<int>& A) {
        this->nums = A;
    }
    
    int sumRange(int i, int j) {
        
        if(this->num_calls == 0)
        {
            // cout<<i<<" "<<j<<endl;
            for(int row = 0; row < this->nums.size(); row++)
            {
                vector<int> temp;
                vector<bool> temp_b;
                for(int col = 0; col < this->nums.size() - row; col++)
                {
                    temp.push_back(0);
                    temp_b.push_back(false);
                }
                sum.push_back(temp);
                computed.push_back(temp_b);
                // cout<<sum[row].size()<<endl;
            }
            
            int sum_ = 0;
            for(int a = 0; a < this->nums.size() - i; a++)
            {
                // cout<<i<<" "<<a<<endl;
                sum_ += this->nums[i + a];
                sum[i][a] = sum_;
                computed[i][a] = true;
            }
            this->num_calls++;
            return sum[i][j - i];
            
        }
        else
        {
            if(computed[i][j - i] == false)
            {
                int sum_ = 0;
                for(int a = 0; a < this->nums.size() - i; a++)
                {
                    sum_ += this->nums[i + a];
                    sum[i][a] = sum_;
                    computed[i][a] = true;
                }
                return sum[i][j - i];
            }
            else
                return sum[i][j - i];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
