class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long long total_time = 0;
        long long last_finish_time = 0;
        for (int i = 0; i < customers.size(); ++i) {
            long long  start_time = customers[i][0];
            int preparation_time = customers[i][1];
            int end_time = max(last_finish_time, start_time) + preparation_time;

            total_time += (end_time - start_time);
            last_finish_time = end_time;
        }

        return (total_time/(customers.size()*1.0));
    }
};
