class Solution {
public:
    bool isValid(string s) {
        stack<char> parenStack;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                parenStack.push(s[i]);
            } else {
                char closeParen = '(';
                if (s[i] == '}') closeParen = '{';
                else if (s[i] == ']') closeParen = '[';

                if (parenStack.size() && parenStack.top() == closeParen)
                    parenStack.pop();
                else
                    return false;
            }
        }

        return parenStack.size() == 0;
    }
};
