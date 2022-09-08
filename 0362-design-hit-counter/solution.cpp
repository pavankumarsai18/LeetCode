class HitCounter {
private:
    deque<pair<int, int>> queue;
    int curTime;
    int numHits;
    const int threshold;
public:
    HitCounter(): threshold(300)
    {
        curTime = 0;
        numHits = 0;
    }
    
    void hit(int timestamp) 
    {
        if(queue.empty())
        {
            queue.push_back({timestamp, 1});
            numHits++;
        }
        else
        {
            if(queue.back().first == timestamp)
            {
                pair<int, int> item = queue.back();
                queue.pop_back();
                queue.push_back({item.first, item.second + 1});
                numHits++;
                
            }
            else
            {
                queue.push_back({timestamp, 1});
                numHits++;
            }
        }
        
        // print(queue);

        
        return;
    }
    void print(deque<pair<int, int>> Q)
    {
        while(!Q.empty())
        {
            cout<<"("<<Q.front().first<<","<<Q.front().second<<") ";
            Q.pop_front();
        }
        cout<<endl;
    }
    
    int getHits(int timestamp)
    {
        // cout<<"timestamp "<<timestamp<<endl;
        // cout<<"(timestamp - front "<<timestamp - queue.front().first<<") "<<threshold<<endl;
        while(!queue.empty() && timestamp - queue.front().first >= threshold)
        {
            numHits -= queue.front().second;
            queue.pop_front();
        }
        // print(queue);

        return numHits;
    }
};
/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
