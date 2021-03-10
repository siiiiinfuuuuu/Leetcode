class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans(n,'a');
        int curr = n-1;
        k-=n;
        while(k>0){
            if(k>=25){
                ans[curr--]+=25;
                k-=25;
            }
            else{
                ans[curr]+=k;
                return ans;
            }
        }
        return ans;
    }
};