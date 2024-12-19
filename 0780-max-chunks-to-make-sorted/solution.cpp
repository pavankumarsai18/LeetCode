class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
       stack<int> mono_stack;

       for (int i = 0; i < arr.size(); i++) {
            if (mono_stack.empty() || mono_stack.top() < arr[i]) {
                mono_stack.push(arr[i]);
            } else {
                int max_value = mono_stack.top();
                while (!mono_stack.empty() &&
                        mono_stack.top() > arr[i]) {
                    mono_stack.pop();
                }
                mono_stack.push(max_value);
            }
       }

       return mono_stack.size();
    }
};
