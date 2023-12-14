class Solution {
public:
    int evaluate(string expression) {
        unordered_map<string, int> varMap;
        return helper(expression, varMap);
    }

    int helper(const string & expr, unordered_map<string, int> & varMap) {

        if (isNumber(expr)) {
            return atoi(expr.c_str());
        }
        
        if(isVar(expr)) {
            return varMap[expr];
        }
        
        int res = 0;
        vector<string> list = parse(expr);
        if (list[0] == "add") {
            res = helper(list[1], varMap) + helper(list[2], varMap);
        } else if (list[0] == "mult") {
            res = helper(list[1], varMap) * helper(list[2], varMap);
        } else {
            unordered_map<string, int> newMap = varMap;

            for (int i = 1; i < list.size() - 1; i+=2) {
                newMap[list[i]] = helper(list[i+1], newMap);
            }

            res = helper(list[list.size() - 1], newMap);
        }
        return res;
    }

    bool isNumber(const string & expr) 
    {return '0' <= expr[0] && expr[0] <= '9' || expr[0] == '-'; }

    bool isVar(const string & expr) {
        return 'a' <= expr[0] && expr[0] <= 'z';
    }

    vector<string> parse(const string & expr) {
        vector<string> ans;
        string subExpr = expr.substr(1, expr.size() - 2);
    
        int startIdx = 0;
        while(startIdx < subExpr.size()) {
            int endIdx = next(subExpr, startIdx);
            
            ans.push_back(subExpr.substr(startIdx, (endIdx - startIdx)));
            startIdx = endIdx + 1;
        }

        return ans;
    }

    int next(const string & expr, int startIdx) {
        int idx = startIdx;

        if (expr[idx] == '(') {
            int count = 1;
            idx++;

            while(idx < expr.size() && count > 0) {
                if (expr[idx] == '(') count++;
                else if (expr[idx] == ')') count--;
                idx++;
            }
        } else {
            while(idx < expr.size() && expr[idx] != ' ') {
                idx++;
            }
        }

        return idx;
    }
};
