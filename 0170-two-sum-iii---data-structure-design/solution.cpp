class TwoSum {
private:
    unordered_map<long long, long long> numCount;
public:
    TwoSum() 
    {
        
    }
    
    void add(int number) {
        auto itr = numCount.find(number);
        if(itr != numCount.end())
        {
            numCount[number]++;
        }
        else{
            numCount[number] = 1;
        }
    }
    
    bool find(int value) 
    {
        for(auto itr = numCount.begin(); itr != numCount.end(); itr++)
        {
            auto find = numCount.find(value - itr->first);
            if(find != numCount.end())
            {
                if((value- itr->first == itr->first) && itr->second > 1)
                    return true;
                else if(value - itr->first != itr->first)
                    return true;
            }
        }
        
        return false;
        
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
