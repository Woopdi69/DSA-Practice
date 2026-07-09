class Solution {
public:
    int mySqrt(int x) {
        if(x == 1 || x == 0) return x;

        int left = 0, right = x, mid = -1;
        while(left <= right){
            mid = left + (right-left)/2;

            long long val = (long long)mid*mid;
            if(val == x){
                return mid;
            }else if(val > x){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return (long long)right;
    }
};