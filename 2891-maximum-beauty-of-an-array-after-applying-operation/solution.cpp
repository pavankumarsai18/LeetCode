class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        // unordered_map<int, int> num_count;
        // int highest_frequency = 0;
        // for (auto num : nums) {
        //     for (int replace_value = max(0, num - k); replace_value <= num + k; replace_value++) {
        //         if (num_count.find(replace_value) == num_count.end()) {
        //             num_count[replace_value] = 0;
        //         }
        //         int new_frequency = ++num_count[replace_value];
        //         highest_frequency = max(highest_frequency, new_frequency);
        //     }
        // }
        // return highest_frequency;

        vector<pair<int, int>> ranges;
        sort(begin(nums), end(nums));
        for (int num: nums) {
            int start = max(0, num - k);
            int end   = num + k + 1;
            ranges.push_back({start, end});
        }


        // for (auto & range: ranges) {
        //     cout << "{ " << range.first << " " << range.second << "} ";
        // }
        // cout << endl;


        // int range_index = 0;
        // int max_frequency = 0;
        // while (range_index < ranges.size()) {
        //     int frequency = 0;
        //     pair<int, int> intersecting_range = ranges[range_index];
            
        //     while (range_index < ranges.size() && intersects(intersecting_range, ranges[range_index])) 
        //     {
        //         intersecting_range = {max(intersecting_range.first, ranges[range_index].first),
        //          min(intersecting_range.second, ranges[range_index].second)};
        //         frequency++;
        //         range_index++;
        //         // cout << "intersecting_range " << intersecting_range.first << " " 
        //         //      << intersecting_range.second << " frequency " << frequency  << endl;
        //     }
            
        //     // cout << frequency << endl;
        //     max_frequency = max(max_frequency, frequency);

        //     if (frequency > 1 && range_index != ranges.size() - 1) {
        //         range_index -= 1;
        //     }
        // }


        // return max_frequency;






        int maxBeauty = 0;
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> counts(maxValue + 1, 0);

        for (int num: nums) {
            counts[max(0, num - k)]++;
            if (num + k + 1 <= maxValue) {
                counts[num+k+1]--;
            }
        }

        int rollingSum = 0;
        for (int count: counts) {
            rollingSum += count;
            maxBeauty = max(maxBeauty, rollingSum);
        }

        return maxBeauty;
    }

    bool intersects(pair<int, int> & range1, pair<int, int> & range2) {
        int start1 = range1.first, end1 = range1.second;
        int start2 = range2.first, end2 = range2.second;
        int intersection = min(end2, end1) - max(start1, start2);
        bool intersects = (intersection > 0);
        return intersects;
    }
};
