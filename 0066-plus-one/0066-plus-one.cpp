class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0; i--){
            int sum = digits[i]+carry;
            digits[i] = sum%10;
            sum /= 10;
            carry = sum;
        }

        if(carry != 0){
            reverse(digits.begin(), digits.end());
            digits.push_back(carry);
            reverse(digits.begin(), digits.end());
        }

        return digits;
    }
};