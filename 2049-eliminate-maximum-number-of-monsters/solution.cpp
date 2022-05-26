class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        // speed = dist/time -> time = dist/speed
        vector<float> time;
        const int n = dist.size();
        
        for(int i = 0; i < n; i++)
        {
            time.push_back((dist[i]*1.0)/speed[i]);
        }
        
        sort(time.begin(), time.end());
        
        int curTime = 0;
        int numKilled = 0;
        for(int i = 0; i < n; i++)
        {
            // cout<<time[i]<<" ";
            if(time[i] > curTime)
            {
                numKilled++;
                curTime++;
            }
            else
                break;
        }
        // cout<<endl;
        
        return numKilled;
        
    }
};
