class Solution {
private:
    int gcd(int a, int b){
        if(b <= 1){
            return a;
        }

        return gcd(b, a%b);
    }

public:
    int gcdOfOddEvenSums(int n) {
        if(n == 1) return 1;
        long long even = 0, odd = 0;
        int count = 0;
        for(int i = 1; i <= 2000 && count/2 < n; i++){
            count++;
            if(i%2 == 0){
                even += i;
            }else{
                odd += i;
            }
        }

        return gcd(even, odd);
    }
};