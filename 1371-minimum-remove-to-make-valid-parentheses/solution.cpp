class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int balance = 0;
        stack<int> index_parenthesis;
        unordered_set<int> remove_idx;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                index_parenthesis.push(i);
            } else if (s[i] == ')') {
                if (index_parenthesis.empty()) {
                    remove_idx.insert(i);
                } else {
                    index_parenthesis.pop();
                }

            }
        }

        while (!index_parenthesis.empty()) {
            remove_idx.insert(index_parenthesis.top());
            index_parenthesis.pop();
        }

        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (remove_idx.find(i) == remove_idx.end()) {
                ans += s[i];
            }
        }

        return ans;
    }
};
