class Solution {
private:
    long long rev(long long x){
        long long ans = 0;
        while(x > 0){
            ans = ans*10 + x%10;
            x /= 10;
        }

        return ans;
    }

public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long x = 0;

        while(n > 0){
            int val = n%10;

            if(val != 0){
                sum += val;
                x = x*10 + val;
            }

            n /= 10;
        }

        x = rev(x);
        return x*sum;
    }
};