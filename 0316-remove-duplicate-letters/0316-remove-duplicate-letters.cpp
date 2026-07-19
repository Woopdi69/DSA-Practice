class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        vector<bool> visited(26, false);
        stack<char> stk;

        for(char c : s){
            if(!visited[c-'a']){
                while(!stk.empty() && c < stk.top() && freq[stk.top()-'a'] > 0){
                    visited[stk.top()-'a'] = false;
                    stk.pop();
                }

                stk.push(c);
                visited[c-'a'] = true;
                freq[c-'a']--;
            }else{
                freq[c-'a']--;
            }
        }

        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};