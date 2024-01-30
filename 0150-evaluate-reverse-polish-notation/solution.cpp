class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> S;

        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int b, a;
                b = S.top(); S.pop();
                a = S.top(); S.pop();

                
                if ( tokens[i] == "+") { 
                    S.push(a + b);
                } else if (tokens[i] ==  "-") {
                    S.push(a - b);
                } else if (tokens[i] == "*") {
                    S.push(a*b);
                } else {
                    S.push(a/b);
                }
            } else {
                S.push(stoi(tokens[i]));
            }
        }

        return S.top();
    }
};
