class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char, int> char_count;
        for (int i = 0; i < s.size(); ++i) {
            char_count[s[i]]++;
        }

        priority_queue<char> maxHeap;
        for (auto & [ch, count]: char_count) {
            maxHeap.push(ch);
        }

        string ans = "";

        while (maxHeap.size()) {
            char ch = maxHeap.top();
            maxHeap.pop();
            int use = min(repeatLimit, char_count[ch]);
            char_count[ch] -= use;
            ans.append(use, ch);

            if (char_count[ch] > 0 && !maxHeap.empty()) {
                char other = maxHeap.top();
                maxHeap.pop();
                ans += other;
                char_count[other]--;

                if (char_count[other] > 0) {
                    maxHeap.push(other);
                }

                maxHeap.push(ch);
            }

        }

        return ans;
    }
};
