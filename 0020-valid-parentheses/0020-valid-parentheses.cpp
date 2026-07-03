class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for(char c : s){
            if(stk.empty() || c == '(' || c == '[' || c == '{'){
                stk.push(c);
            }else{
                if((stk.top() != '(' && c == ')') || 
                (stk.top() != '[' && c == ']') ||
                (stk.top() != '{' && c == '}')){
                    return false;
                }

                stk.pop();
            }
        }

        return stk.size() == 0;
    }
};