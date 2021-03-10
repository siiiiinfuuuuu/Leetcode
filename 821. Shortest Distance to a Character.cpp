class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans(s.size(),-1);
        vector<int> curr;
        for(int i = 0; i < s.size(); i++)
            if(s[i] == c){
                ans[i] = 0;
                curr.push_back(i);
            }
        int d = 1;
        while(curr.size()!=0){
            vector<int> next;
            for(int i = 0; i < curr.size() ; i++){
                if(curr[i] -1 >= 0 && ans[curr[i] -1] == -1){
                    ans[curr[i] -1] = d;
                    next.push_back(curr[i] -1);
                }
                if(curr[i] + 1 < s.size() && ans[curr[i] + 1] == -1){
                    ans[curr[i] + 1] = d;
                    next.push_back(curr[i] + 1);
                }
            }
            curr = next;
            d++;
        }
        return ans;
    }
};