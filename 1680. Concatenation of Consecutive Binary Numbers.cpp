class Solution {
public:
    int concatenatedBinary(int n) {
        long last = 1;
        long ans = 1;
        int last_d = 1;
        int digit;
        for(int i = 2; i<=n ; i++){
            int tmp = i>>last_d;
            digit = last_d+tmp;
            ans = ((last<<digit)+i)%1000000007;
            last = ans;
            last_d = digit;
        }
        return ans;
    }
};