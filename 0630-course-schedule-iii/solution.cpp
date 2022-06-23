class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) 
    {
        auto cmp = [](vector<int> & course1, vector<int> & course2)
        {
            return course1[1] < course2[1];
        };
        
        
        sort(courses.begin(), courses.end(), cmp);
        
        int n       = courses.size();
        priority_queue<int> pq;
        int time  = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(time+ courses[i][0] <= courses[i][1]){
                pq.push(courses[i][0]);
                time += courses[i][0];
            }
            else if(pq.size() > 0 && pq.top() > courses[i][0])
            {
                time += courses[i][0] - pq.top(); pq.pop();
                pq.push(courses[i][0]);
            }
            
        }
        
        return pq.size();
    }
};
