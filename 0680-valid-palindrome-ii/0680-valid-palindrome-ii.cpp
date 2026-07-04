class Solution {
private:
    bool pali(string s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        int count = 0;

        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else if(s[left] != s[right]){
                if(pali(s, left, right-1) || pali(s, left+1, right)){
                    return true;
                }else{
                    return false;
                }
            }
        }

        return true;
    }
};