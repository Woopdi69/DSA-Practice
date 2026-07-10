class Solution {
private:
    pair<int, int> isPali(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return {left+1, right-1};
    }

public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            auto [left1, right1] = isPali(s, i, i);
            auto [left2, right2] = isPali(s, i, i+1);
            int len1 = right1-left1+1;
            int len2 = right2-left2+1;

            int left, right;
            if(len1 > len2){ 
                left = left1;
                right = right1;
            } else {
                left = left2;
                right = right2;
            }

            string temp = s.substr(left, right-left+1);
            if(temp.size() > ans.size()){
                ans = temp;
            }
        }

        return ans;
    }
};