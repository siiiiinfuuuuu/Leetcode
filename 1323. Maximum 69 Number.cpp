class Solution {
public:
    int maximum69Number (int num) {
        vector<int> digit;
        while(num!=0){
            digit.push_back(num%10);
            num/=10;
        }
        for(auto it = digit.rbegin();it!=digit.rend();it++){
            if(*it==6){
                *it = 9;
                break;
            }
        }
        int ans = 0;
        int tmp = 1;
        for(auto it = digit.begin();it!=digit.end();it++){
            ans+=tmp*(*it);
            tmp*=10;
        }
        return ans;
    }
};