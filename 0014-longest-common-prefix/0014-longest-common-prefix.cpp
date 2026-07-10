class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string ans = "";
        sort(strs.begin(), strs.end());
        int i = 0;
        while(i < strs[0].size() && i < strs[strs.size()-1].size()){
            if(strs[0][i] != strs[strs.size()-1][i]){
                break;
            }
            ans += strs[0][i];
            i++;
        }
        return ans;
    }
};