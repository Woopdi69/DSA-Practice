class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int ans = 0, cur = 0;
        vector<int> freq(125, 0);

        while(right < s.size()){
            freq[s[right]-' ']++;
            cur++;

            while(left < s.size() && freq[s[right]-' '] > 1){
                cur--;
                freq[s[left]-' ']--;
                left++;
            }

            ans = max(ans, cur);
            right++;
        }

        return ans;
    }
};