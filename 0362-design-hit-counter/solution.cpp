class HitCounter {
private:
    int numHits;
    deque<pair<int, int>> hitQueue;
    const int threshold;
public:
    HitCounter() : threshold(300) {
        numHits = 0;
    }
    
    void hit(int timestamp) {
        if (hitQueue.empty()) {
            hitQueue.push_back({timestamp, 1});
        } else {
            auto lastElement = hitQueue.back();
            if (lastElement.first == timestamp) {
                hitQueue.pop_back();
                hitQueue.push_back({timestamp, lastElement.second + 1});
            } else {
                hitQueue.push_back({timestamp, 1});
            }
        }
        numHits++;
    }
    
    int getHits(int timestamp) {
        while(hitQueue.size() && timestamp - hitQueue.front().first >= threshold) {
            numHits -= hitQueue.front().second;
            hitQueue.pop_front();
        }

        return numHits;
        
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
